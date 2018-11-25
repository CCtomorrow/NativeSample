package com.ai.hellosample;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

import com.ai.hellosample.tools.Util;

public class MainActivity extends AppCompatActivity {

    private TextView vText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        vText = findViewById(R.id.content_txt);
        vText.setText(Util.dynamicGenerateKey("rty"));
    }
}
