package com.lucasncv.controleremoto;

import java.io.OutputStream;
import java.util.Set;
import java.util.UUID;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.view.Menu;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.widget.ImageButton;
import android.util.Log;

/**
 * @author      Lucas Carvalho
 * @version     1.3
 * @since       07-2013
 */
public class MainActivity extends Activity implements SensorEventListener
{
	/**
	 * O adaptador bluetooth.
	 */
	BluetoothAdapter adapter;
	
	/**
	 * O socket bluetooth.
	 */
	BluetoothSocket socket;
	
	/**
	 * O stream de saída serial.
	 */
	OutputStream ostream = null;
	
	/**
	 * Gerenciador de sensores do Android.
	 */
	SensorManager sensorManager = null;
	
	/**
	 * Uma referência ao acelerômetro.
	 */
	Sensor accelerometer = null;
	
	/**
	 * Id do pedal que está atualmente pressionado.
	 */
	int pedalDown = -1;
	
	/**
	 * Chamado pelo Android no momento em que esta atividade é criada.
	 *
	 * @param  savedInstanceState O estado salvo anteriormente.
	 */
	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);		
		setContentView(R.layout.activity_main);
		
		sensorManager = (SensorManager)getSystemService(SENSOR_SERVICE);
		accelerometer = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
		sensorManager.registerListener(this, accelerometer, SensorManager.SENSOR_DELAY_NORMAL);
		
		// prepara os pedais
		PreparePedal((ImageButton)this.findViewById(R.id.imageButton1));
		PreparePedal((ImageButton)this.findViewById(R.id.imageButton2));
	}
	
	/**
	 * Prepara um pedal.
	 *
	 * @param  btn O botão que corresponde ao pedal.
	 */
	void PreparePedal(ImageButton btn)
	{
		final int id = btn.getId();
		
		btn.setOnTouchListener(new OnTouchListener()
		{
			@Override
		    public boolean onTouch(View v, MotionEvent event)
			{
		        if (event.getAction() == MotionEvent.ACTION_DOWN && pedalDown == -1)
		        {
		        	pedalDown = id;
		        	onPedalDown(id);
		        }
		        else if (event.getAction() == MotionEvent.ACTION_UP && pedalDown == id)
		        {
		        	onPedalUp(id);
		        	pedalDown = -1;
		        }
		        
		        return true;
			}
		});
	}
	
	/**
	 * Um dos pedais foi pressionado.
	 *
	 * @param  id O id do pedal.
	 */
	void onPedalDown(int id)
	{
		if (id == R.id.imageButton1)
			sendMessage("1002;");
		else
			sendMessage("1001;");	
	}
	
	/**
	 * Um dos pedais foi solto.
	 *
	 * @param  id O id do pedal.
	 */
	void onPedalUp(int id)
	{
		sendMessage("1003;");
	}

	/**
	 * Função implementada automaticamente pelo android.
	 */
	@Override
	public boolean onCreateOptionsMenu(Menu menu)
	{
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
	/**
	 * Inicializa o dispositivo bluetooth.
	 *
	 * @param  view A view que chama este callback.
	 */
	public void initBT(View view)
	{
		adapter = BluetoothAdapter.getDefaultAdapter();
		
		if (adapter == null)
		{
			Log.w(null, "Adaptador não encontrado.");
			return;
		}

		if (!adapter.isEnabled())
		{
			Intent enableBluetooth = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
			startActivityForResult(enableBluetooth, 0);
		}
		
		Log.i(null, "Adaptador pronto.");

		Set<BluetoothDevice> pairedDevices = adapter.getBondedDevices();
		
		if (pairedDevices.size() > 0)
		{
			for (BluetoothDevice device : pairedDevices)
			{
				Log.i(null, "Dispositivo: " + device.getName());

				if (device.getName().equals("itead"))
				{
					openBT(device);
					break;
				}
			}
		}
	}
	
	/**
	 * Envia uma mensagem pela stream bluetooth.
	 *
	 * @param  str A string a ser enviada.
	 */
	public void sendMessage(String str)
	{
		try
		{
			ostream.write(str.getBytes());
		}
		catch (Exception e)
		{
			Log.e(null, "Erro ao enviar mensagem.", e);
		}
	}
	
	/**
	 * Prepara a stream serial do bluetooth.
	 *
	 * @param  device O dispositivo bluetooth em questão.
	 */
	void openBT(BluetoothDevice device)
	{
		try
		{
			Log.i(null, "Conectando a " + device.getName() + "...");
			UUID uuid = UUID.fromString("00001101-0000-1000-8000-00805f9b34fb");
			socket = device.createRfcommSocketToServiceRecord(uuid);    
			socket.connect();
			ostream = socket.getOutputStream();
			Log.i(null, "Stream de saída pronta.");
		}
		catch (Exception e)
		{
			Log.e(null, "Erro ao abrir stream de saída.", e);
		}
	}
	
	/**
	 * Função implementada automaticamente pela interface do
	 * acelerômetro.
	 *
	 * @param  ev O evento do acelerômetro.
	 */
	public void onSensorChanged(SensorEvent ev)
	{
		if (ostream != null && ev.sensor.getType() == Sensor.TYPE_ACCELEROMETER)
		{
			float x = -ev.values[1];
			
			if (x < -4)
				x = -4;
			else if (x > 4)
				x = 4;
			
			if (Math.abs(x) < 1)
				x = 0;
			
			x /= 4;
			x += 1;
			x /= 2;
			
			int nx = (int)(x * 180) + 2000;			
			Log.i(null, "Dir: " + nx);
			sendMessage(nx + ";");
		}
	}

	/**
	 * Função implementada automaticamente pela interface do
	 * acelerômetro.
	 *
	 * @param  arg0 O acelerômetro em questão.
	 * @param  arg1 A nova acurácia.
	 */
	@Override
	public void onAccuracyChanged(Sensor arg0, int arg1)
	{
		// TODO Auto-generated method stub	
	}
}
