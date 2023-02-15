import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.StringTokenizer;
public class Mark extends JFrame implements ActionListener
{
    JButton rollno = new JButton("Roll No");
    JButton name = new JButton("Name");
    JButton mark1 = new JButton("Mark 1");
    JButton mark2 = new JButton("Mark 2");
    JButton mark3 = new JButton("Mark 3");
    JTextField Trollno = new JTextField();
    JTextField Tmark1 = new JTextField();
    JTextField Tmark2 = new JTextField();
    JTextField Tmark3 = new JTextField();
    JTextField Tname = new JTextField();
    Mark()
    {
        setLayout(null);
        add(rollno);
        add(name);
        add(mark1);
        add(mark2);
        add(mark3);

        rollno.setBounds(100,100,100,30);
        name.setBounds(100,150,100,30);
        mark1.setBounds(100,200,100,30);
        mark2.setBounds(100,250,100,30);
        mark3.setBounds(100,300,100,30);

        add(Trollno);
        add(Tname);
        add(Tmark1);
        add(Tmark2);
        add(Tmark3);
        rollno.addActionListener(this);
        Trollno.setBounds(250,100,210,30);
        Tname.setBounds(250,150,210,30);
        Tmark1.setBounds(250,200,210,30);
        Tmark2.setBounds(250,250,210,30);
        Tmark3.setBounds(250,300,210,30);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(500,500);
    }
    public void actionPerformed(ActionEvent e)
    {
        try
        {
            int flag=1;
            String rNumber = Trollno.getText();
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            String line;
            while((line=br.readLine())!=null)
            {
                StringTokenizer st = new StringTokenizer(line," ");
                while(st.hasMoreTokens())
                {
                    st.nextToken();
                    if(st.nextToken().equals(rNumber))
                    {
                        flag=0;
                        st.nextToken();
                        Tname.setText(st.nextToken());
                        st.nextToken();
                        Tmark1.setText(st.nextToken());
                        st.nextToken();
                        Tmark2.setText(st.nextToken());
                        st.nextToken();
                        Tmark3.setText(st.nextToken());
                        break;
                    }
                }
            }
            if(flag==1)
            {
                Tname.setText("");
                Tmark1.setText("");
                Tmark2.setText("");
                Tmark3.setText("");
            }
            br.close();
        }
        catch(Exception er)
        {
            System.out.println(er);
        }
    }
    public static void main(String[] args) {
        new Mark();
    }
}
