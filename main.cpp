#include <iostream>
using namespace std;

int main()
{
    cout << "MASMORRA LABIRINTICA CARDIACA" << endl;
    cout << "Mova-se com WASD (frente, esquerda, tras, direita)." << endl;
    cout << "Rotacione com (R). Vire o labirinto com (Q)." << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "Voce se encontra em uma masmorra escura..." << endl;

    char direcao;

    bool vitoria = false;

    bool monstro1 = true;
    bool monstro2 = true;
    bool monstro3 = true;
    bool monstro4 = true;

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
            cout << "A sua esquerda tem uma porta." << endl;
            cout << "LV: " << lv << endl;
            cout << "----------------------------------------------------------------------------"<<endl;
            cout << "Opcoes: esquerda (a)." << endl;
            cin >> direcao;

            if (direcao == 'a')
            {
                direcao = 'n';

                cout << "Voce passa pela porta..." << endl;
                cout << "----------------------------------------------------------------------------"<<endl;

                sala = 2;
            }
        }

        // SALA 2
        if (sala == 2)
        {
            cout << "Sala 2." << endl;
            cout << "LV: " << lv << endl;
            cout << "----------------------------------------------------------------------------"<<endl;

            if (monstro1 == true)
            {
                cout << "Um slime (LV 2) bloqueia o caminho." << endl;
                cout << "Enfrentar o slime? (seguir para esquerda)" << endl;
                cout << "Opcoes: esquerda (a), cima (w) ou direita (d)." << endl;
                cout << "----------------------------------------------------------------------------"<<endl;

                cin >> direcao;

                if (direcao == 'w')
                {
                    direcao='n';
                    sala = 4;
                }
                else if (direcao == 'a' && lv >= 2)
                {
                    lv = lv + 2;

                    monstro1 = false;

                    cout << "Voce venceu a luta!" << endl;
                    cout << "Seu nivel agora e: " << lv << endl;
                    cout << "----------------------------------------------------------------------------"<<endl;

                    sala = 3;
                }
                else if (direcao == 'a' && lv < 2)
                {
                    cout << "Voce morreu." << endl;

                    return 0;
                }
                else if (direcao == 'd')
                {
                sala = 1;     
                }
                
            }
            else
            {
                cout << "Opcoes: esquerda (a), cima (w) ou direita (d)." << endl;
                cin>>direcao;
                if (direcao == 'w')
                {
                    direcao='n';
                    sala = 4;
                } 
                else if (direcao == 'a')
                {
                    direcao='n';
                    sala = 3;
                }
                else if (direcao == 'd')
                {
                    direcao='n';
                    sala = 1;
                }

                
            }
        }

        // SALA 3
        if (sala == 3)
        {
            cout << "Sala 3." << endl;
            cout << "LV: " << lv << endl;
            cout << "----------------------------------------------------------------------------"<<endl;

            cout << "Opcoes: rotacionar (r) ou direita. (d)" << endl;
            cout << "----------------------------------------------------------------------------"<<endl;

            cout << "Você pode retornar ou rotacionar as portas do labirinto no sentido horario quantas vezes gostaria de rotacionar? (digite r para rotacionar)" << endl;
            cout << "----------------------------------------------------------------------------"<<endl;

            cin >> direcao;

            if (direcao == 'r')
            {
                direcao='n';
                rotacao = rotacao + 1;

                if (rotacao > 5)
                {
                    rotacao = rotacao - 5;
                }

                switch (rotacao)
                {
                case 1:
                    cout << "você está na posição 0°!" << "\n";
                    break;
                case 2:
                    cout << "você está na posição 90°!" << "\n";
                    break;
                case 3:
                    cout << "você está na posição 180°!" << "\n";
                    break;
                case 4:
                    cout << "você está na posição 270°!" << "\n";
                    break;
                case 5:
                    cout << "você está na posição 360°!" << "\n";
                    break;


                    
                default:
                    break;
                }

            }
            else if (direcao== 'd')
            {
                direcao='n';
                sala=2;
            }
        }

        // SALA 4
        if (sala == 4)
        {
            cout << "Sala 4." << endl;
            cout << "LV: " << lv << endl;
            cout << "----------------------------------------------------------------------------"<<endl;
            
            cout << "Opcoes: cima (w), baixo (s), esquerda (a) ou direita (d)." << endl;
            cin >> direcao;
                if (direcao == 'w')
                {
                    direcao='n';
                    sala = 10;
                }
                else if (direcao == 'a')
                {
                  if (rotacao == 5)
                  {
                    direcao = 'n';
                    sala = 6;
                  } else {
                    direcao = 'n';
                    cout << "----------------------------------------------------------------------------"<<endl;
                    cout << "sua rotação não permite. rotação necessária: 360 \n";
                    cout << "----------------------------------------------------------------------------"<<endl;
                  }
                }
                else if (direcao == 's')
                {
                    direcao='n';
                    sala = 2;
                }
                else if (direcao == 'd')
                {
                  if (rotacao == 1)
                  {
                    direcao = 'n';
                    sala = 5;
                  } else {
                    direcao = 'n';
                    cout << "----------------------------------------------------------------------------"<<endl;
                    cout << "sua rotação não permite. rotação necessária: 0° \n";
                    cout << "----------------------------------------------------------------------------"<<endl;
                  }
                    
                }
        }
        
                
            // SALA 5
        if (sala == 5) {
            cout << "Sala 5." << endl;
            cout << "LV: " << lv << endl;
            cout << "----------------------------------------------------------------------------"<<endl;
            cout << "Opcoes: esquerda (a)." << endl;
            cin >> direcao;
            if (direcao == 'a'){
                direcao = 'n';
                sala = 4;
            } 
        }
            
            // SALA 6
            if (sala == 6) {
                cout << "Sala 6." << endl;
                cout << "LV: " << lv << endl;
                cout << "----------------------------------------------------------------------------"<<endl;
                cout << "Opcoes: Virar mapa (q), direita (d)" << endl;
                cin >> direcao;
                if (direcao == 'q'){
                    sala = 7;
                } else if (direcao == 'd'){
                    sala = 4;
             
                }
            }
            
            // SALA 7
            if (sala == 7) {
              std::cout << "sala 10";
              return 0;
            }
            
            // SALA 10
            if (sala == 10) {
              std::cout << "sala 10";
              return 0;
            }



    }

    cout << "Voce ganhou!!" << endl;

    return 0;
}
