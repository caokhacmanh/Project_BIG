import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;


public class GUI {
    public static void main(String[] args) {
        new GUIFrame();
    }    
}



class GUIFrame extends JFrame implements ActionListener{

    static boolean status = false;
    static double tmp = 0, firstVal = 0, secondVal = 0, finalAns = 0;
    static char mathKey = '+';

    GUIButton buttNum1 = new GUIButton("1", 0,65);
    GUIButton buttNum2 = new GUIButton("2", 65,65);
    GUIButton buttNum3 = new GUIButton("3", 130,65);
    GUIButton buttNum4 = new GUIButton("4", 0,130);
    GUIButton buttNum5 = new GUIButton("5", 65,130);
    GUIButton buttNum6 = new GUIButton("6", 130,130);
    GUIButton buttNum7 = new GUIButton("7", 0,195);
    GUIButton buttNum8 = new GUIButton("8", 65,195);
    GUIButton buttNum9 = new GUIButton("9", 130,195);
    GUIButton buttNum0 = new GUIButton("0", 0,260);
    GUIButton buttMulti = new GUIButton("x", 195,65);
    GUIButton buttAdd = new GUIButton("+", 195,130);
    GUIButton buttMinu = new GUIButton("-", 195,195);
    GUIButton buttDivi = new GUIButton("/", 195,260);
    GUIButton submit = new GUIButton("=", 65,260);
    GUIButton clear = new GUIButton("C", 130,260);
    
    JPanel displayPanel = new JPanel();

    JLabel displayLabel = new JLabel();

    GUIFrame(){
        buttNum1.addActionListener(this);
        buttNum2.addActionListener(this);
        buttNum3.addActionListener(this);
        buttNum4.addActionListener(this);
        buttNum5.addActionListener(this);
        buttNum6.addActionListener(this);
        buttNum7.addActionListener(this);
        buttNum8.addActionListener(this);
        buttNum9.addActionListener(this);
        buttNum0.addActionListener(this);
        buttMulti.addActionListener(this);
        buttAdd.addActionListener(this);
        buttMinu.addActionListener(this);
        buttDivi.addActionListener(this);
        submit.addActionListener(this);
        clear.addActionListener(this);
        
        displayLabel.setFont(new Font("Comic sans", Font.BOLD, 40));

        displayPanel.setBounds(0, 0, 300, 65);
        displayPanel.setBackground(Color.LIGHT_GRAY);
        displayPanel.add(displayLabel);

        this.setSize(300,500);
        this.setBackground(new Color(240,240,240));
        this.setTitle("Calculator by H1A4C3K");
        this.setVisible(true);
        this.setResizable(false);
        this.setLayout(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        this.add(buttNum1); 
        this.add(buttNum2); 
        this.add(buttNum3); 
        this.add(buttNum4); 
        this.add(buttNum5); 
        this.add(buttNum6); 
        this.add(buttNum7); 
        this.add(buttNum8);
        this.add(buttNum9); 
        this.add(buttNum0);
        this.add(buttMulti);
        this.add(buttAdd);
        this.add(buttMinu);
        this.add(buttDivi);
        this.add(submit);
        this.add(clear);
        this.add(displayPanel);
    }



    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == buttAdd){
            if(mathKey == '+'){
                secondVal = secondVal + firstVal;
            }
            if(mathKey == '-'){
                secondVal = secondVal - firstVal;
            }
            if(mathKey == '*'){
                secondVal = secondVal * firstVal;
            }
            if(mathKey == '/'){
                secondVal = secondVal / firstVal;
            }
            mathKey = '+';
            firstVal = 0;
        }
        if(e.getSource() == buttMinu){
            if(mathKey == '+'){
                secondVal = secondVal + firstVal;
            }
            if(mathKey == '-'){
                secondVal = secondVal - firstVal;
            }
            if(mathKey == '*'){
                secondVal = secondVal * firstVal;
            }
            if(mathKey == '/'){
                secondVal = secondVal / firstVal;
            }
            mathKey = '-';
            firstVal = 0;
        }
        if(e.getSource() == buttMulti){
            if(mathKey == '+'){
                secondVal = secondVal + firstVal;
            }
            if(mathKey == '-'){
                secondVal = secondVal - firstVal;
            }
            if(mathKey == '*'){
                secondVal = secondVal * firstVal;
            }
            if(mathKey == '/'){
                secondVal = secondVal / firstVal;
            }
            mathKey = '*';
            firstVal = 0;
        }
        if(e.getSource() == buttDivi){
            if(mathKey == '+'){
                secondVal = secondVal + firstVal;
            }
            if(mathKey == '-'){
                secondVal = secondVal - firstVal;
            }
            if(mathKey == '*'){
                secondVal = secondVal * firstVal;
            }
            if(mathKey == '/'){
                secondVal = secondVal / firstVal;
            }
            mathKey = '/';
            firstVal = 0;
        }

        if(e.getSource() == buttNum1) firstVal = firstVal * 10 + 1;
        if(e.getSource() == buttNum2) firstVal = firstVal * 10 + 2;
        if(e.getSource() == buttNum3) firstVal = firstVal * 10 + 3;
        if(e.getSource() == buttNum4) firstVal = firstVal * 10 + 4;
        if(e.getSource() == buttNum5) firstVal = firstVal * 10 + 5;
        if(e.getSource() == buttNum6) firstVal = firstVal * 10 + 6;
        if(e.getSource() == buttNum7) firstVal = firstVal * 10 + 7;
        if(e.getSource() == buttNum8) firstVal = firstVal * 10 + 8;
        if(e.getSource() == buttNum9) firstVal = firstVal * 10 + 9;
        if(e.getSource() == buttNum0) firstVal = firstVal * 10;

        if(e.getSource() == submit){
            switch(mathKey){
                case '+': secondVal = secondVal + firstVal; break;
                case '-': secondVal = secondVal - firstVal; break;
                case '*': secondVal = secondVal * firstVal; break;
                case '/': secondVal = secondVal / firstVal; break;
            }
            displayLabel.setText("ans = " + secondVal);
        }else{
            displayLabel.setText("" + firstVal);
        }
        
        if(e.getSource() == clear){
            firstVal = 0;
            secondVal = 0;
            mathKey = '+';
            displayLabel.setText("" + firstVal);
        }
        // System.out.println(mathKey); // for test
        
    }
}



class GUIButton extends JButton{
    GUIButton(String buttonName, int buttonX, int buttonY){
        this.setText(buttonName);
        this.setLayout(null);
        this.setFocusable(false);
        this.setBounds(buttonX, buttonY, 64, 64);
        this.setFont(new Font("Comic sans", Font.BOLD, 30));
        
    
    }
}


// you can't see my testing cause i use windows+G