#include <iostream>
using namespace std;

int main()
{
    cout << "MASMORRA LABIRÍNTICA CARDÍACA" << endl;
    cout << "Mova-se com WASD (frente, esquerda, trás, direita)." << endl;
    cout << "Rotacione com (R). Vire o labirinto com (Q)." << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Você se encontra em uma masmorra escura..." << endl;

    char direcao;

    bool vitoria = false;

    bool monstro1 = true;
    bool monstro2 = true;
    bool monstro3 = true;
    bool monstro4 = true;
    string resposta1;
    string resposta2;

    int rotacao = 1;
    int sala = 1;
    int lv = 2;

    direcao = 'N';

    while (vitoria == false)
    {
        // SALA 1
        if (sala == 1)
        {
            cout << "----------------------------------------------------------------------------"<<endl;
            cout << "SALA: 1"<<endl;
            cout << "A sua frente tem uma porta." << endl;
            cout << "LV: " << lv << endl;
            cout << "Você só pode seguir em frente."<<endl;
            cout << "----------------------------------------------------------------------------"<<endl;

            cin >> direcao;

            if (direcao == 'w')
            {
                direcao = 'n';

                cout << "Você passa pela porta..." << endl;
                cout << "----------------------------------------------------------------------------"<<endl;

                sala = 2;
            }
            else
            {
                direcao='n';
                cout<<"Você deu de cara na parede."<<endl;
            }
        }

        // SALA 2
        if (sala == 2)
        {
            cout << "SALA: 2" << endl;
            cout << "LV: " << lv << endl;

            if (monstro1 == true)
            {
                cout << "Um slime (LV 2) bloqueia o caminho." << endl;
                cout << "Enfrentar o slime? (seguir para frente)" << endl;
                cout << "Opções: frente, trás ou direita." << endl;
                cout << "----------------------------------------------------------------------------"<<endl;

                cin >> direcao;
                
                if (direcao == 'a')
                {
                    direcao='n';
                    cout<<"Você bateu de cara na parede..."<<endl;
                }
                else if (direcao == 's')
                {
                    direcao='n';
                    sala = 1;
                }
                else if (direcao == 'd')
                {
                    direcao='n';
                    sala = 4;
                }
                else if (direcao == 'w' && lv >= 2) //sistema completo para luta.
                {
                    lv = lv + 2;

                    monstro1 = false;

                    cout << "Você venceu a luta!" << endl;
                    cout << "Seu nível agora é: " << lv << endl;
                    cout << "----------------------------------------------------------------------------"<<endl;

                    sala = 3;
                }
                else if (direcao == 'w' && lv < 2)
                {
                    cout << "Você morreu." << endl;

                    return 0;
                }
            }
            else // sala 2 sem monstro.
            {
                cout << "Opções: frente, trás ou direita." << endl;
                cin>>direcao;
                if (direcao == 'd')
                {
                    direcao='n';
                    sala = 4;
                }
                if (direcao == 'w')
                {
                    direcao='n';
                    sala = 3;
                }
                if (direcao == 's')
                {
                    direcao='n';
                    sala = 1;
                }
                if (direcao == 'a')
                {
                    direcao='n';
                    cout<<"Você bateu de cara na parede..."<<endl;
                }
            }
        }

        // SALA 3
        if (sala == 3)
        {
            cout << "sala 3 lv:" << lv << endl;

            cout << "Você pode retornar ou rotacionar as portas do labirinto no sentido horário. (digite R para rotacionar)" << endl;
            cout << "----------------------------------------------------------------------------"<<endl;

            cin >> direcao;

            if (direcao == 'r')
            {
                direcao='n';
                rotacao = rotacao + 1;

                if (rotacao > 4)
                {
                    rotacao = rotacao - 4;
                }
                if (rotacao == 1)
                {
                    cout<<"sua rotação é 0°";
                } else if (rotacao == 2)
                {
                    cout<<"sua rotação é 90";
                } else if (rotacao == 3)
                {
                    cout<<"sua rotação é 180";
                } else if (rotacao == 4)
                {
                    cout<<"sua rotação é 270";
                }
                 else if (rotacao)
                {
                    cout<<"sua rotação é 360°";
                }
                
                
                
                


            }
            else if (direcao== 's')
            {
                direcao='n';
                sala=2;
            }
            else if (direcao != 'r')
            {
                direcao = 'n';
                cout<<"Você bateu de cara na parede..."<<endl;
            }
        }

        // SALA 4
        if (sala == 4)
        {
            cout << "Sala 4." << endl;
            cout << "LV: " << lv << endl;
            cout << "Opções: frente, trás e esquerda." << endl;
            cout << "----------------------------------------------------------------------------"<<endl;

            cin >> direcao;
                if (direcao == 'w')
                {
                    if (rotacao!=4)
                    {
                    direcao='n';
                    cout << "Você não pode seguir por esse caminho; precisa da rotação 4 para passar."<<endl;
                    }
                    else
                    {
                    direcao='n';
                    sala = 6;
                    }
                }

                if (direcao == 'a')
                {
                    direcao='n';
                    sala = 2;
                }
                
                 if (direcao == 's')
                {
                    if (rotacao !=2)
                    {
                    direcao='n';
                    cout<<"Você não pode seguir por esse caminho; a rotação necessária é 2."<<endl;
                    }
                    else
                    {
                        direcao='n';
                        sala=5;
                    }
                }
                
                 if (direcao == 'd')
                {
                    direcao='n';
                    cout<<"Você bateu de cara na parede..."<<endl;
                }
        }   
        //SALA 5.
        if (sala == 5)
        {
            cout << "Sala 5." << endl;
            cout << "LV: " << lv << endl;
            cout << "Opções: voltar." << endl;
            cout << "----------------------------------------------------------------------------"<<endl;
            
            cin>>direcao;
            if (direcao == 'w')
            {
                direcao='n';
                sala=4;
            }
            else
            {
                direcao='n';
                cout<<"Você bateu de cara na parede..."<<endl; 
            }
            
        }
        //sala 6.
        if (sala == 6)
        {
            cout << "Sala 6." << endl;
            cout << "LV: " << lv << endl;
            cout << "Opções: voltar e seguir em frente." << endl;
            cout << "----------------------------------------------------------------------------"<<endl;
            
            cin >> direcao;
            if (direcao == 'w')
            {
                direcao='n';
                sala=7;
            }
            if (direcao == 's')
            {
                direcao='n';
                sala=4;
            }
            if (direcao == 'd' || direcao == 'a')
            {
                direcao='n';
                cout << "Você deu de cara na parede." << endl;
            }
        }
         // SALA 7 com monstro
        if (sala == 7)
        {
            cout << "SALA: 7" << endl;
            cout << "LV: " << lv << endl;

            if (monstro2 == true)
            {
                cout << "Um minotauro (LV 6) bloqueia o caminho." << endl;
                cout << "Enfrentar o minotauro? (seguir para frente)" << endl;
                cout << "Opções: frente, trás, direita ou esquerda." << endl;
                cout << "----------------------------------------------------------------------------"<<endl;

                cin >> direcao;
                
                if (direcao == 'a')
                {
                    direcao='n';
                    sala=8;
                }
                if (direcao == 's')
                {
                    direcao='n';
                    sala = 6;
                }
                if (direcao == 'd')
                {
                    direcao='n';
                    sala = 9;
                }
                if (direcao == 'w' && lv >= 6) //sistema completo para luta.
                {
                    lv = lv + 2;

                    monstro2 = false;

                    cout << "Você venceu a luta!" << endl;
                    cout << "Seu nível agora é: " << lv << endl;
                    cout << "----------------------------------------------------------------------------"<<endl;

                    sala = 11;
                }
                if (direcao == 'w' && lv < 6)
                {
                    cout << "Você morreu." << endl;

                    return 0;
                }
            }
            else // sala 7 sem monstro.
            {
                cout << "Opções: frente, trás, direita ou esquerda." << endl;
                cin>>direcao;
                if (direcao == 'd')
                {
                    direcao='n';
                    sala = 9;
                }
                else if (direcao == 's')
                {
                    direcao='n';
                    sala = 6;
                }
                if (direcao == 'a')
                {
                    direcao='n';
                    sala=8;
                }
                if (direcao == 'w')
                {
                    direcao='n';
                    sala=11;
                }
            }
        }
        //sala 8.
        if (sala == 8)
            {
                cout << "sala 8 lv:" << lv << endl;

            cout << "Você pode retornar ou rotacionar as portas do labirinto no sentido horário. (digite R para rotacionar)" << endl;
            cout << "----------------------------------------------------------------------------"<<endl;

            cin >> direcao;

            if (direcao == 'r')
            {
                direcao='n';
                rotacao = rotacao + 1;

                if (rotacao > 4)
                {
                    rotacao = rotacao - 4;
                }

                if (rotacao == 1)
                {
                    cout<<"sua rotação é 0°";
                } else if (rotacao == 2)
                {
                    cout<<"sua rotação é 90";
                } else if (rotacao == 3)
                {
                    cout<<"sua rotação é 180";
                } else if (rotacao == 4)
                {
                    cout<<"sua rotação é 270";
                }
                 else if (rotacao)
                {
                    cout<<"sua rotação é 360°";
                }
                
                
            }
            if (direcao == 'd')
            {
                direcao='n';
                sala=7;
            }
            else if (direcao != 'r' && direcao != 'd')  
            {
                direcao = 'n';
                cout<<"Você bateu de cara na parede..."<<endl;
            }
            
     
        }
         // sala 9.
        if (sala == 9)
        {
            cout << "SALA: 9" << endl;
            cout << "LV: " << lv << endl;

            if (monstro3 == true)
            {
                cout << "Uma aranha (LV 4) bloqueia o caminho." << endl;
                cout << "Enfrentar a aranha? (seguir para trás)" << endl;
                cout << "Opções: esquerda ou ir para a ou para trás." << endl;
                cout << "----------------------------------------------------------------------------"<<endl;

                cin >> direcao;
                
                if (direcao == 'w')
                {
                    direcao='n';
                    cout<<"Você bateu de cara na parede..."<<endl;
                }
                if (direcao == 'd')
                {
                    direcao='n';
                    cout<<"Você bateu de cara na parede..."<<endl;
                }
                if (direcao == 'a')
                {
                    direcao='n';
                    sala = 7;
                }
                if (direcao == 's' && lv >= 4) //sistema completo para luta.
                {
                    lv = lv + 4;

                    monstro3 = false;

                    cout << "Você venceu a luta!" << endl;
                    cout << "Seu nível agora é: " << lv << endl;
                    cout << "----------------------------------------------------------------------------"<<endl;
                    
                    if (lv == 10)
                    {
                        direcao='n';
                        sala=10;
                    }
                    else
                    {
                        direcao='n';
                        cout << "Você ainda não possui o nível necessário para passar por essa porta. Nível necessário: LV 10."<< endl;
                    }
                }
                if (direcao == 's' && lv < 4)
                {
                    cout << "Você morreu." << endl;

                    return 0;
                }
            }
            else // sala 9 sem monstro.
            {
                cout << "Opções: frente, trás, direita ou esquerda." << endl;
                cin>>direcao;
                if (direcao == 'd')
                {
                    direcao='n';
                    cout<<"Você bateu de cara na parede..."<<endl;
                }
                if (direcao == 's')
                {
                    if (lv == 10)
                    {
                        direcao='n';
                        sala=10;
                    }
                    else
                    {
                        direcao='n';
                        cout << "Você ainda não possui o nível necessário para passar por essa porta. Nível necessário: LV 10."<< endl;
                    }
                }
                if (direcao == 'a')
                {
                    direcao='n';
                    sala=7;
                }
                if (direcao == 'w')
                {
                    direcao='n';
                    cout<<"Você bateu de cara na parede..."<<endl;
                }
            }
        }
        //sala 10.
        if (sala == 10)
        {
            cout << "Sala 10." << endl;
            cout << "LV: " << lv << endl;
            cout << "Você vê uma grande porta. Essa provavelmente é a saída da masmorra...";
            cout << "Opções: voltar e sair (S)." << endl;
            cout << "----------------------------------------------------------------------------"<<endl;
            
            cin >> direcao;
            
            if (direcao =='w')
            {
                direcao='n';
                sala=9;
            }
            if (direcao =='a')
            {
                direcao='n';
                cout<<"Você bateu de cara na parede..."<<endl;
            }
            if (direcao =='s')
            {
                direcao='n';
                cout<<"A porta cria olhos e boca, ela olha para você e diz:"<<endl;
                cout<<"Os delírios dos xamãs liberam o caminho... você pode compreende-los?"<<endl;
                cout<<"Dê a ela as respostas das charadas:"<<endl;
                cin >> resposta1;
                cin >> resposta2;
                cout<< resposta1<< resposta2<< endl;
                if (resposta1=="acido" && resposta2=="chuva")
                {
                    vitoria=true;
                }
                else
                {
                    cout << "--hmm...--"<<endl;
                    cout << "A porta não parece satisfeita...";
                }
                
            }
            if (direcao =='d')
            {
                direcao='n';
                cout<<"Você bateu de cara na parede..."<<endl;
            }
        }
        //sala 11
        if (sala==11)
        {
            cout << "Sala 11." << endl;
            cout << "LV: " << lv << endl;
            cout << "Você vê uma grande sala. Ela tem diversas portas, mas parece que você precisa girá-las para passar."<<endl;
            cout << "Opções: seguir em frente, ir para a direita, ir para a esquerda, voltar." << endl;
            cout << "----------------------------------------------------------------------------"<<endl;
            cin >> direcao;
            
            if (direcao =='w')
            {
                direcao='n';
                if (rotacao==2)
                {
                    sala=13;
                }
                else
                {
                    cout << "Você não pode passar por essa porta. (rotação necessária:2)"<<endl;
                }
            }
            if (direcao =='a')
            {
                direcao='n';
                if (rotacao==1)
                {
                    sala=14;
                }
                else
                {
                    cout << "Você não pode passar por essa porta. (rotação necessária:1)"<<endl;
                }
            }
            if (direcao =='s')
            {
                direcao='n';
                sala=7;
            }
            if (direcao =='d')
            {
                direcao='n';
                if (rotacao==3)
                {
                    sala=12;
                }
                else
                {
                    cout << "Você não pode passar por essa porta. (rotação necessária:3)"<<endl;
                }
            }
        }
        //sala 12.
        if (sala==12)
        {
            cout << "Sala 12." << endl;
            cout << "LV: " << lv << endl;
            cout << "Você encontra um xamã. Apesar de ser um humano preso aqui, ele não parece sentir fome ou sede..."<<endl;
            cout << "Opções: falar com o xamã (D), seguir em frente ou ir para a esquerda." << endl;
            cout << "----------------------------------------------------------------------------"<<endl;
            cin >> direcao;
            
            if (direcao=='w')
            {
                direcao='n';
                if (rotacao==3)
                {
                    sala=13;
                }
                else
                {
                    cout << "Você não pode passar por essa porta. (rotação necessária:3)"<<endl;
                }
            }
            
            if (direcao=='a')
            {
                direcao='n';
                if (rotacao==3)
                {
                    sala=11;
                }
                else
                {
                    cout << "Você não pode passar por essa porta. (rotação necessária:3)"<<endl;
                }
            }
            
            if (direcao=='s')
            {
                direcao='n';
                cout<<"Você bateu de cara na parede..."<<endl;
            }
            
            if (direcao=='d')
            {
                direcao='n';
                cout << "Você diz ao xamã que procura a saída da masmorra..."<<endl;
                cout << "Xamã: Eu caio em pé e corro deitado... O que eu sou?" <<endl;
                cout << "Você não entende como isso pode ajudá-lo, mas decide tentar se lembrar."<<endl;
            }
            
        }
        // sala 13.
        if (sala == 13)
        {
            cout << "Sala 13." << endl;
            cout << "LV: " << lv << endl;
            cout << "Você pode girar a sala (R)."<<endl;
            cout << "Opções: direita, esquerda, girar e voltar." << endl;
            cout << "----------------------------------------------------------------------------"<<endl;
            cin >> direcao;
            
            if (direcao == 'w')
            {
                direcao='n';
                cout<<"Você bateu de cara na parede..."<<endl;
            }
            if (direcao == 'a')
            {
                direcao='n';
                if (rotacao == 1)
                {
                    sala=14;
                }
                else
                {
                    cout << "Você não pode passar por essa porta. (rotação necessária:1)"<<endl;
                }
            }
            if (direcao == 's')
            {
                direcao='n';
                if (rotacao == 2)
                {
                    sala=11;
                }
                else
                {
                    cout << "Você não pode passar por essa porta. (rotação necessária:2)"<<endl;
                }
            }
             if (direcao == 'd')
            {
                direcao='n';
                if (rotacao == 3)
                {
                    sala=12;
                }
                else
                {
                    cout << "Você não pode passar por essa porta. (rotação necessária:3)"<<endl;
                }
            }
            if (direcao == 'r')
            {
                direcao='n';
                rotacao = rotacao + 1;

                if (rotacao > 4)
                {
                    rotacao = rotacao - 4;
                }
                cout<<rotacao<<endl;
            }
        }
        // sala 14
        if (sala == 14)
        {
            cout << "Sala 14." << endl;
            cout << "LV: " << lv << endl;
            cout << "Você encontra um xamã. Apesar de ser um humano preso aqui, ele não parece sentir fome ou sede..."<<endl;
            cout << "Opções: falar com o xamã (A), seguir em frente ou ir para a esquerda." << endl;
            cout << "----------------------------------------------------------------------------"<<endl;
            cin >> direcao;
            
            if (direcao=='w')
            {
                direcao='n';
                if (rotacao==1)
                {
                    sala=13;
                }
                else
                {
                    cout << "Você não pode passar por essa porta. (rotação necessária:1)"<<endl;
                }
            }
            
            if (direcao=='d')
            {
                direcao='n';
                if (rotacao==1)
                {
                    sala=11;
                }
                else
                {
                    cout << "Você não pode passar por essa porta. (rotação necessária:1)"<<endl;
                }
            }
            
            if (direcao=='s')
            {
                direcao='n';
                cout<<"Você bateu de cara na parede..."<<endl;
            }
            
            if (direcao=='a')
            {
                direcao='n';
                cout << "Você diz ao xamã que procura a saída da masmorra..."<<endl;
                cout << "Xamã: Na cozinha, eu dou o azedo do limão e do vinagre. O que eu sou?" <<endl;
                cout << "Você não entende como isso pode ajudá-lo, mas decide tentar se lembrar."<<endl;
            }
        }    
    }

    cout << "Você ganhou!!" << endl;

    return 0;
}