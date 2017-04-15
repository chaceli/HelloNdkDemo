package com.wangjin.hellondkdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // 调用c中的方法弹出Toast
        Toast.makeText(this, helloFromJni(), Toast.LENGTH_LONG).show();
        // java调用c然后回调java方法，在logcat中打印  hahahahaahah====
        callBackJavafromC();
    }

    static {
        // 加载so库文件，这个是固定写法，需要调用so库文件的方法，首先需要加载so库
        System.loadLibrary("hello"); // hello是我们在build.gradle中定义的，要一致
    }


    public native String helloFromJni();

    public native void callBackJavafromC();


    public void logout() {
        System.out.println("hahahahahahahahahah===");
    }
}
