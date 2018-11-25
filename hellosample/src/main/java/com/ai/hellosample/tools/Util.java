package com.ai.hellosample.tools;

/**
 * <b>Project:</b> NativeSample <br>
 * <b>Create Date:</b> 2018/11/3 <br>
 * <b>@author:</b> qy <br>
 * <b>Address:</b> qingyongai@gmail.com <br>
 * <b>Description:</b>  <br>
 */
public class Util {

    static {
        System.loadLibrary("Hello-Util");
    }

    public static native String getDeviceId();

    public static native String dynamicGenerateKey(String name);
}
