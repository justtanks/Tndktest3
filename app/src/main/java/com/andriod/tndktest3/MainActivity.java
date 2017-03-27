package com.andriod.tndktest3;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    //添加对native包名的调用
    static {
        System.loadLibrary("native-lib");
    }

    TextView textView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        this.textView= (TextView) findViewById(R.id.test);
        String s="hello";
        String l="to you ";
        Log.e("MyApp", "onCreate: "+appendString(s,l) );
        textView.setText(appendString(s,l));

    }
    //建立navtive 接口方法，然后实现和c方法对接
    public native  String getString();
    public native  int getMyInt();
    public native String appendString(String str1,String str2);

}
