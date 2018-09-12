#include<iostream>
#include<sstream>
#include<fstream>
#include<fnmatch.h>
#include<cstring>
#include <unistd.h>
using namespace std;
class controller
{
  public:
    int key = 123;
    string gname;//全局用户名，表示登录用户的名字，后文中添加用户要判断
    void show();//logo显示
    bool logincheck();//登录验证
    void menu();//菜单选择
    void addagent();//添加特工
    void agentinfo();//特工查询
    void addpow();//添加异能人
    void powinfo();//异能人查询
    void search();//装模作样的搜索
    void deleagent();//删除
    void delepow();//异能人删除
};


void controller::show()
{
  cout<<"\n\t _____ _   _ _____ _____ _    ______";
  cout<<"\n\t/  ___| | | |_   _|  ___| |   |  _  \\";
  cout<<"\n\t\\ `--.| |_| | | | | |__ | |   | | | |";
  cout<<"\n\t` --. \\  _  | | | |  __|| |   | | | |";
  cout<<"\n\t/\\__/ / | | |_| |_| |___| |___| |/ /" ;
  cout<<"\n\t\\____/\\_| |_/\\___/\\____/\\_____/___/ ";
cout<<"\n\n\t*******CopyRight@卡布奇诺*************\n";
}


void controller::search()
{
        system("clear");
        show();
        cout<<"正在调用神盾局全宇宙最强搜索."<<endl;
        sleep(1);
        system("clear");
        show();
        cout<<"正在调用神盾局全宇宙最强搜索.."<<endl;
        sleep(1);
        system("clear");
        show();
        cout<<"正在调用神盾局全宇宙最强搜索..."<<endl;
        sleep(1);
        system("clear");
        show();
        cout<<"正在调用神盾局全宇宙最强搜索...."<<endl;
        sleep(1);
        system("clear");
        show();
        cout<<"正在调用神盾局全宇宙最强搜索....."<<endl;
        sleep(1);
        system("clear");
        show();
        cout<<"正在调用神盾局全宇宙最强搜索......"<<endl;
        sleep(1);
        system("clear");
        show();
        cout<<"正在调用神盾局全宇宙最强搜索......."<<endl;
        sleep(1);
        system("clear");
        show();
        cout<<"正在调用神盾局全宇宙最强搜索........"<<endl;
        sleep(1);
        system("clear");
                show();
        cout<<"正在调用神盾局全宇宙最强搜索........."<<endl;
        sleep(1);
        system("clear");
                show();
        cout<<"正在调用神盾局全宇宙最强搜索.........."<<endl;
        system("clear");
        show();
        cout<<"结果如下:"<<endl;
}
bool controller::logincheck()
{//登录验证
  show();
  string name;

  for(int count=1;count<=3;count++)
  {
    cout<<"Input SHIELD Number/Name:";
    cin>>name;
    char *password = getpass("Input Password:");//所谓的掩码，键盘输入屏幕却没有回显
    for(int i=0;i<strlen(password);i++)
    {
      password[i] = password[i]^key;
    }
    string n,p;//两个临时变量
    ifstream in("agent.txt");//特工登录文件
    do{
    if(in.eof())
        continue;
      string s;//又是个临时变量，保存读取的文件内容
      getline(in,s);//读取每一行
      istringstream sin(s);//定义sin流
      sin>>n>>p;
      if((name==n)&&(password==p))
      {
        gname = name;//标记登录的用户名
        return true;
      }
    }while(!in.eof());
  }
  cout<<"Srroy You can't Log In !"<<endl;
  return false;
}

void controller::addagent(){
  //添加特工信息
  string name,n,password;
  char sex;
  int rank=0;
  cout << "Please enter Name: ";
  cin.ignore();
  getline(cin, name);
  cout << "Please enter Password(必须是数字): ";
  cin>>password;
  //password = password ^ password;//密码加密，也防止模糊查找时被找到
  for(int i=0;i<password.size();i++)
  {
    password[i] = password[i]^key;
  }
  cout << "             Sex:(M/F) ";
  cin >> sex;
  while (sex != 'M' || sex != 'F') {
      if (sex == 'M' || sex == 'F')
          break;
      cerr << "\nWrong sex. Please enter M(Male) or F(Female): ";
      cin >> sex;
  }
  while (!cin) {
      cin.clear();
      cin.ignore(1024, '\n');
      cerr << "\nWrong sex. Please enter M(Male) or F(Female): ";
      cin >> sex;
      if (cin)
          break;
  }
  cin.ignore();
  cout << "             Rank(小于登录用户rank): ";
  cin>>rank;
  //读取文件，判断登录用户权限是否大于要添加的用户权限
  int ranktrue = 0;//判断rank是否合格
  ifstream agent("agent.txt");//特工登录文件
  do{
    if(agent.eof())
      continue;
    string s,n,p,se;//又是个临时变量，保存读取的文件内容
    int r;//rank
    getline(agent,s);//读取每一行
    istringstream sin(s);//定义sin流
    sin>>n>>p>>se>>r;//name,password,sex,rank
      if(gname==n)
      {
        if(r>rank)
        {
          rank = rank;
          ranktrue = 1;//rank合格
        }
        else{
          cout<<"你只能添加rank比你低的特工"<<endl;
          break;
        }
      }
    }while(!agent.eof());
  agent.close();
  
  
  //判断添加用户是否已经存在
  ifstream in("agent.txt");
  string s1;//临时变量
  int flag = 0;//标志位，为0则不存在
  while(getline(in,s1))
  {
    istringstream sin(s1);
    sin>>n;//读取文件
    if(name==n)
    {
      cout<<"账号已存在!"<<endl;
      flag = 1;
      in.close();//账号存在
      break;
    }
    else
    {
      continue;
    }
  }
      if((!flag)&&(ranktrue))
      {
        //账号不存在则写入
        ofstream out;
        out.open("agent.txt",ios::out | ios::app|ios::binary);
        if(out.is_open())
        {
          out<<name<<"\t"<<password<<"\t"<<sex<<"\t"<<rank<<"\r\n";
          out.close();
        }
      }
  in.close();
}

void controller::agentinfo()
{//特工查询
  string name;//特工名字
  ifstream info("agent.txt");
  int flag = 0;//标记位，０为查找失败
  if(!info)
  {
    cout<<"哦豁,完蛋,文件被删了!!"<<endl;
  }
  else
  {
    cout<<"请输入要查询的特工名字:";
    cin>>name;
    for(string s;getline(info,s);)//读取info每行
    {
      string n,p,sex;//name,sex
      int r;//rank
      istringstream sin(s);
      sin>>n;//读取每行开头姓名
      if(name == n)
      {
        flag = 1;//找到置为１
        sin>>p>>sex>>r;//把要的信息都读出来
        search();
        cout<<"姓名:"<<n<<"\t性别"<<sex<<"\t权限"<<r<<endl;
      }
    }
  }
  if(!flag)
  {
    search();
    cout<<"哦豁！没有找到相关特工"<<endl;
  }
}


void controller::addpow()
{
  string name,pow,n;//名字和超能力
  cout<<"请输入异能人员名字:";
  cin>>name;
  cout<<"请输入异能人的超能力:";
  cin>>pow;
  ifstream in("xx.txt");
  string s1;//临时变量
  int flag = 0;//标志位，为0则不存在
  while(getline(in,s1))
  {
    istringstream sin(s1);
    sin>>n;//读取文件
    if(name==n)
    {
      cout<<"账号已存在!"<<endl;
      flag = 1;
      in.close();//账号存在
      break;
    }
    else
    {
      continue;
    }
  }
      if(!flag)
      {
        //账号不存在则写入
        ofstream out;
        out.open("xx.txt",ios::out | ios::app|ios::binary);
        if(out.is_open())
        {
          out<<name<<"\t"<<pow<<"\r\n";
          out.close();
        }
      }
  in.close();
}

void controller::powinfo()
{
  string name;//特工名字
  ifstream info("xx.txt");
  int flag = 0;//标记位，０为查找失败
  if(!info){
    cout<<"哦豁,完蛋,文件被删了!!"<<endl;
  }
  else
  {
    cout<<"请输入要查询异能人的名字:";
    cin>>name;
    for(string s;getline(info,s);)//读取info每行
    {
      string n,p;//name,超能力
      istringstream sin(s);
      sin>>n;//读取每行开头姓名
      if(name == n)
      {
        flag = 1;//找到置为１
        sin>>p;//把要的信息都读出来
        search();
        cout<<"姓名:"<<n<<"\t超能力:"<<p<<endl;
      }
    }
    if(!flag)
    {
      search();
      cout<<"没有找到相关异人"<<endl;
    }
  }
}


void controller::deleagent()
{
  ifstream in("agent.txt");
  if(!in)
  {
    cout<<"文件不存在，请新建";
  }
  else 
  {
   cout<<"请输入要删除的特工名：";
   string name;
   cin>>name;
   do{
     string n,p,s,r;//name,password,sex,rank
     string ss;
     getline(in,ss);//每次一行
     istringstream sin(ss);
     sin>>n;
     ofstream out("reagent.txt",ios::app);
     if(name!=n)
     {
       out<<ss<<endl;//不是要删的跳过
     }
     out.close();
   }while(!in.eof());
    in.close(); 
  }
  system("rm agent.txt");//删除文件副本
  system("mv reagent.txt agent.txt");//
}



void controller::delepow()
{
    ifstream in("xx.txt");
  if(!in)
  {
    cout<<"文件不存在，请新建";
  }
  else 
  {
   cout<<"请输入要删除的异能人名：";
   string name;
   cin>>name;
   do{
     string n,r;//name,password,sex,rank
     string ss;
     getline(in,ss);//每次一行
     istringstream sin(ss);
     sin>>n;
     ofstream out("rexx.txt",ios::app);
     if(name!=n)
     {
       out<<ss<<endl;//不是要删的跳过
     }
     out.close();
   }while(!in.eof());
    in.close(); 
  }
  system("rm xx.txt");//删除文件副本
  system("mv rexx.txt xx.txt");//
}

void controller::menu()
{                                                //菜单
  system("clear");
  show();
  int options=0;
  cout<<"\n\t********1.特工录入********";
  cout<<"\n\t********2.特工查询********";
  cout<<"\n\t********3.异能人员录入***";
  cout<<"\n\t********4.异能人员查询*******";
  cout<<"\n\t********5.特工删除**********";
  cout<<"\n\t********6.异能人员删除**********";
  cout<<"\n\t********7.退出*************"<<endl;
  cin>>options;
  switch(options)
  {
    case 1:
      system("clear");
      show();
      addagent();//特工录入
      break;
    case 2:
      system("clear");
      show();
      agentinfo();//特工查询
      break;
    case 3:
      system("clear");
      show();
      addpow();//异能人添加
      break;
    case 4:
      system("clear");
      show();
      powinfo();//异能人查询
      break;
    case 5:
      system("clear");
      show();
      deleagent();//删除特工
    case 6:
      system("clear");
      show();
      delepow();//删除特工
    case 7:
      cout<<"Welcome to log in again"<<endl;
      break;
  }
}

int main()
{
  controller con;
  if(con.logincheck())
  {
    con.menu();
  }

}

