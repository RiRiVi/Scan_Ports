#include <iostream>
#include <cstring>

int min_port;
int max_port;

int netsik(int port){

    std::cout << "Check ports:" << port << "\n";
    int flag = 0;
    char command[1000];
    sprintf(command,"netstat -an | grep :'%d'",port);
    FILE *fp = popen(command,"r");
    if(fp != NULL)
    {
        char buff[1024];
        for ( ; fgets(buff, sizeof(buff), fp); )
        {
            std::cout << buff;
            flag = 1;
        }

        pclose(fp);
    }
    if(flag == 0){
        std::cout << " CLOSE"<< "\n";
    }

}

int netsik2(){

    int flag = 0;
    char command[1000];
    sprintf(command,"netstat -l");
    FILE *fp = popen(command,"r");
    if(fp != NULL)
    {
        char buff[1024];
        for ( ; fgets(buff, sizeof(buff), fp); )
        {
            std::cout << buff;
            flag = 1;
        }

        pclose(fp);
    }
    if(flag == 0){
        std::cout << " CLOSE"<< "\n";
    }

}

int netsik3(){

    int flag = 0;
    char command[1000];
    sprintf(command,"netstat -npl");
    FILE *fp = popen(command,"r");
    if(fp != NULL)
    {
        char buff[1024];
        for ( ; fgets(buff, sizeof(buff), fp); )
        {
            std::cout << buff;
            flag = 1;
        }

        pclose(fp);
    }
    if(flag == 0){
        std::cout << " CLOSE"<< "\n";
    }

}

int from_to(int min_port,int max_port){
   for (int port = min_port; port <= max_port; ++port)
   {
        netsik(port);
    }

}

int main(){
    int nom;
    cout << "Введите: 1 для просмотра статуса определенных портов портов, 2 для просмотра статистики сетевых интерфейсов, 3 для просмотра всеx прослушиваемых портов" << "\n";
    cin >> nom;
    if (nom == 1)
    {
        cout << "port checks from ";
        cin >> min_port;
        cout << "to";
        cin >> max_port;
        cout << "port checks from " << min_port << " to " << max_port << endl;
        from_to(min_port,max_port);

    } else if (nom == 2){
        netsik2();
    }else if (nom == 3){
        netsik3();
    }

    return 0;
}
