package com.example.wilson.humancharacteristics;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.example.wilson.humancharacteristics.CameraDetect.CameraDetectActivity;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        Button btStart = (Button)this.findViewById(R.id.button);
        btStart.setOnClickListener(new Button.OnClickListener() {
            public void onClick(View v) {
                // Tạo một Intent:
                // (Mang nội dung sẽ gửi tới Example1Activity).
                Intent myIntent = new Intent(MainActivity.this, CameraDetectActivity.class);
                MainActivity.this.startActivity(myIntent);
            }
        });
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

}
