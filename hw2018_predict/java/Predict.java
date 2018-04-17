package com.elasticcloudservice.predict;

import com.elasticcloudservice.bean.*;

import static com.elasticcloudservice.bean.InputData.*;

import java.util.HashMap;
import java.util.Map;

/**
 * 静态导入了InputData,小心定义局部变量
 */
public class Predict {
    public static String[] predictVm(String[] ecsContent, String[] inputContent) {
        init(inputContent);
        TrainData trainData = new TrainData(ecsContent);
        OutputData outputData = new OutputData();
        predict(outputData, trainData);
        Place.place(outputData);
        return outputData.toStrings();
    }

    private static void predict(OutputData outputData, TrainData trainData) {
        Map<Flavor, int[]> listMap = new HashMap<>();
        for (Flavor flavor : flavors) {
            listMap.put(flavor, new int[trainDateLen]);
        }
        for (FlavorItem flavorItem : trainData.flavorItems) {
            listMap.get(flavorItem.flavor)[flavorItem.time - trainBeginTime]++;
        }
        for (Flavor flavor : flavors) {
            outputData.setCount(flavor, predictS4(listMap.get(flavor)));
        }
    }

    /**
     * 将一段时间作为整体
     */
    private static int[] changTime(int[] time, int space) {
        int[] retv = new int[time.length - space + 1];
        int sum = 0;
        for (int i = 0; i < space; i++) {
            sum += time[i];
        }
        retv[0] = sum;
        for (int i = 1; i < retv.length; i++) {
            sum -= time[i - 1];
            sum += time[i + space - 1];
            retv[i] = sum;
        }
        return retv;
    }
    private static int[] changTime2(int[] time, int space) {
        int[] retv = new int[time.length / space ];
        int sum = 0,j,i;
		for(j=0;j<time.length/space;j++){
			retv[j]=0;
			for (i = 0; i < space; i++){
				retv[j]+=time[j*space+i];
			} 
		}
        return retv;
    }

    private static int predictS(int[] times) {
        //float a = 0.191f;
		int mark=0,mark2=0,thiMaxTime=0,secMaxTime=0,maxTime=0,sumTime=0;
		for(int i=0;i<times.length;i++)
		{
			sumTime+=times[i];
			if(times[i]>maxTime) {
				mark2=mark;
				mark=i;
				
				thiMaxTime=secMaxTime;
				secMaxTime=maxTime;
				maxTime=times[i];
			}
		}
//第一次		times[mark]=(sumTime)/(times.length);//去掉最大值，消去可能的异常点
//第二次78.        
		times[mark]=secMaxTime;//去掉最大值，消去可能的异常点
//		times[mark]=thiMaxTime;//去掉最大值，消去可能的异常点		
//        times[mark2]=thiMaxTime;//去掉次大值，消去可能的异常点
		
        float a = 0.4f;
        double[] s1 = new double[times.length];
        s1[1] = a * times[1] + (1 - a) * times[0];
        for (int i = 2; i < times.length; i++) {
            s1[i] = a * times[i] + (1 - a) * s1[i - 1];
        }
        //a=0.65f;
        double S = a * s1[2] + (1 - a) * s1[1];
        for (int i = 3; i < times.length; i++) {
            S = a * s1[i] + (1 - a) * S;
        }

        return (int) (S * predictDateLen);
    }
	
    private static int predictS2(int[] times) {
        //float a = 0.191f;
        float a = 0.4f;
        double[] s1 = new double[times.length];
        s1[1] = a * times[1] + (1 - a) * times[0];
        for (int i = 2; i < times.length; i++) {
            s1[i] = a * times[i] + (1 - a) * s1[i - 1];
        }
        //a=0.65f;
        double S = a * s1[2] + (1 - a) * s1[1];
        for (int i = 3; i < times.length; i++) {
            S = a * s1[i] + (1 - a) * S;
        }
        int[] retv = changTime(times, predictDateLen);
        int sum = 0;
        for (int i : retv) {
            sum += i;
        }
        sum /= retv.length;

        return (int) (S * 7) + sum * (predictDateLen - 7) / predictDateLen;
    }

    private static int predictS3(int[] times) {
        int[] retv = changTime(times, predictDateLen);
        //float a = 0.191f;

        float a = 0.51f;
        double[] s1 = new double[retv.length];
        double[] s2 = new double[retv.length];
        s1[1] = a * retv[1] + (1 - a) * retv[0];
        for (int i = 2; i < retv.length; i++) {
            s1[i] = a * retv[i] + (1 - a) * s1[i - 1];
        }
        s2[2] = a * s1[2] + (1 - a) * s1[1];
        for (int i = 3; i < retv.length; i++) {
            s2[i] = a * s1[i] + (1 - a) * s2[i - 1];
        }

        double S = a * s2[3] + (1 - a) * s2[2];
        for (int i = 4; i < retv.length; i++) {
            S = a * s2[i] + (1 - a) * S;
        }
        return (int) (S);
    }
    private static int predictS4(int[] times) {
        //float a = 0.191f;
	//	times= changTime2(times, predictDateLen);
		int mark=0,secMaxTime=0,maxTime=0;
		int mark2=0,secMinTime=0,minTime=0;
		for(int i=0;i<times.length;i++)
		{
			if(times[i]>maxTime) {
				mark=i;
				
				secMaxTime=maxTime;
				maxTime=times[i];
			}
			if(times[i]<minTime) {
				mark2=i;
				
				secMinTime=maxTime;
				minTime=times[i];
			}
		}
		times[mark2]=secMinTime;//去掉最小值
		times[mark]=secMaxTime;//去掉最大值，消去可能的异常点		
        float a = 0.511f;
        double[] s1 = new double[times.length+predictDateLen];
        s1[1] = a * times[1] + (1 - a) * times[0];
        for (int i = 2; i < times.length; i++) {
            s1[i] = a * times[i] + (1 - a) * s1[i - 1];
        }
        //a=0.65f;
        double S = a * s1[2] + (1 - a) * s1[1];
        for (int i = 3; i < times.length; i++) {
            S = a * s1[i] + (1 - a) * S;
        }
		double[] test_time=new double[predictDateLen];
		test_time[0]=S;
		for(int i=1;i<predictDateLen;i++){
			s1[times.length-1+i]=a*test_time[i-1]+(1-a)*s1[times.length-2+i];
			S=a * s1[times.length-1+i] + (1 - a) * S;
			test_time[i]=S;
		}
		S=0;
		for(int i=0;i<predictDateLen;i++){
			S+=test_time[i];
		}
        return (int) (S);
//		return (int)(test_time[predictDateLen-1]*predictDateLen);
    }
	
    private static int predictS_big(int[] times) {
        //float a = 0.191f;
	//	times= changTime2(times, predictDateLen);
		int mark=0,secMaxTime=0,maxTime=0;
		int mark2=0,secMinTime=0,minTime=0;
		for(int i=0;i<times.length;i++)
		{
			if(times[i]>maxTime) {
				mark=i;
				
				secMaxTime=maxTime;
				maxTime=times[i];
			}
			if(times[i]<minTime) {
				mark2=i;
				
				secMinTime=maxTime;
				minTime=times[i];
			}
		}
		times[mark2]=secMinTime;//去掉最小值
		times[mark]=secMaxTime;//去掉最大值，消去可能的异常点		
        float a = 0.4f;
        double[] s1 = new double[times.length];
        s1[1] = a * times[1] + (1 - a) * times[0];
        for (int i = 2; i < times.length; i++) {
            s1[i] = a * times[i] + (1 - a) * s1[i - 1];
        }
        //a=0.65f;
        double S = a * s1[2] + (1 - a) * s1[1];
        for (int i = 3; i < times.length; i++) {
            S = a * s1[i] + (1 - a) * S;
        }

        return (int) (S * predictDateLen);
    }

}

	