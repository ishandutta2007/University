import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Calculatorv2 {

    
    boolean hasDot = false;
    double prenum = 0.0;
    String inputStr = "";
    char operator = '+';
    
    
    
    private double cal(double d1, double d2, char op){
        if(op == '=' || op == '+')
            d1 = d1 + d2;
        else if(op == '-')
            d1 = d1 - d2;
        else if(op == '*')
            d1 = d1 * d2;
        else if(op == '/')
            d1 = d1 / d2;
        return d1;
    }
    private void inputnum(String digit){
        inputStr += digit;
        tf.setText(inputStr);
    }
    private void inputdot(){
        if(hasDot == true)
            return;
        inputStr += ".";
        tf.setText(inputStr);
    }
    private void inputop(char op){
        double tmp = Double.valueOf(inputStr);
        prenum = cal(prenum, tmp, operator);
        inputStr = "";
        operator = op;
        tf.setText(String.valueOf(prenum));
        hasDot = false;
    }
    
    
    private void reset(){
        System.out.println("in reset");
        hasDot = false;
        prenum = 0.0;
        String inputStr = "";
        tf.setText("");
        
    }
    final static JTextField tf = new JTextField();
    JPanel p = new JPanel(new GridLayout(0, 4, 1, 1));
    
    public Calculatorv2() {
        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        } catch (Exception e) {
        }
        String[] str = { "7", "8", "9", "/", "4", "5", "6", "*", "1", "2", "3", "-", ".", "0", "=", "+", "C"};
        char ch[] = { '7', '8', '9', '/', '4', '5', '6', '*', '1', '2', '3', '-', '.', '0', '=', '+' ,'c'};
        tf.setPreferredSize(new Dimension(1,40));

        tf.setEnabled(false);
        tf.setBackground(Color.white);
        tf.setForeground(Color.green);
        for (int i = 0; i <= 16; i++) {
            final JButton btn = new JButton(String.valueOf(String.valueOf(ch[i])));    
            btn.setFont(new Font("Dialog",1,20));
            btn.setOpaque(true);
            p.add(btn);

            btn.getInputMap(JComponent.WHEN_IN_FOCUSED_WINDOW).put(
                    KeyStroke.getKeyStroke(ch[i]), "PressKeyAction");
            btn.getActionMap().put("PressKeyAction", new AbstractAction() {
                public void actionPerformed(ActionEvent e) {
                    System.out.println("in actionPerformed key");
                    //监测键盘的输入情况
                    //当监测到有显示的按键被按下时，调用。
                    
                    //btn.doClick 就是使按键做相应的 被click 的操作
                    btn.doClick();
                }
            });
            btn.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e) {
                    // 此为按键被click 时调用的部分
                    
                    String tpd = btn.getText();
                    if(tpd.equals("+") || tpd.equals("-") || tpd.equals("*") || tpd.equals("/") || tpd.equals("="))
                        inputop(tpd.charAt(0));
                    
                    else if(tpd.equals("c")) reset();
                    else if(tpd.equals(".")) inputdot();
                    else inputnum(tpd);
                    System.out.println(tpd);
                    System.out.println("in actionPerformed button");
//                    tf.setText(tf.getText() + btn.getText());
                    btn.requestFocus();
                }
            });

            btn.addKeyListener(new KeyListener()
            {
                public void keyPressed(KeyEvent e) 
                {
//                    btn.setForeground(Color.BLACK);//改成换图标
                }
                public void keyReleased(KeyEvent e) 
                {
//                    btn.setForeground(Color.black);//改成换图标
                }
                public void keyTyped(KeyEvent e) {
                }
            });
        }

 

        JFrame f = new JFrame();
        JComponent contentPane = (JComponent) f.getContentPane();
        contentPane.setLayout(new BorderLayout(0, 5));
        contentPane.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));

        f.getContentPane().add(p, BorderLayout.CENTER);
        f.getContentPane().add(tf, BorderLayout.NORTH);
        f.pack();
        f.setTitle("Calculator v2.0");
        f.setBounds(0,100,300,350);
        f.setLocationRelativeTo(null);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
    public static void main(String[] args){
        Calculatorv2 cal = new Calculatorv2();
    }
}
