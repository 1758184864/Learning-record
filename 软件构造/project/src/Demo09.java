import java.util.Random;

/**
 * @author John.Cena
 * @date 2022/9/26 22:51
 * @Description:
 */

// 9.按照任务一的设计和输出，完成程序编写，输出加法练习和减法联系各两套
public class Demo09 {
    public static void main(String[] args) {
        int m = 0, n = 0, value = 0;
        char o = '+';
        Random random = new Random();
        int ov = random.nextInt(2); // 0：加号； 1：减号
        for (int i = 0; i < 50; i++) {
            if(ov == 0) {
                o = '+';
                do {
                    m = random.nextInt(101);
                    n = random.nextInt(101);
                    value = m + n;
                }while(value > 100);
            }else {
                o = '-';
                do {
                    m = random.nextInt(101);
                    n = random.nextInt(101);
                    value = m - n;
                }while(value < 0);
            }
            System.out.println((i+1) + "\t:" + m + o + n + " = " + value);
            ov = random.nextInt(2);
        }
    }
}
