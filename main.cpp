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
            cout << "A sua frente tem uma porta." << endl;
            cout << "LV: " << lv << endl;
            cout << "----------------------------------------------------------------------------"<<endl;

            cin >> direcao;

            if (direcao == 'w')
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
                cout << "Enfrentar o slime? (seguir para frente)" << endl;
                cout << "Opcoes: frente, tras ou direita." << endl;
                cout << "----------------------------------------------------------------------------"<<endl;

                cin >> direcao;

                if (direcao == 'd')
                {
                    direcao='n';
                    sala = 4;
                }
                else if (direcao == 'w' && lv >= 2)
                {
                    lv = lv + 2;

                    monstro1 = false;

                    cout << "Voce venceu a luta!" << endl;
                    cout << "Seu nivel agora e: " << lv << endl;
                    cout << "----------------------------------------------------------------------------"<<endl;

                    sala = 3;
                }
                else if (direcao == 'w' && lv < 2)
                {
                    cout << "Voce morreu." << endl;

                    return 0;
                }
            }
            else
            {
                cout << "Opcoes: frente, tras ou direita." << endl;
                cin>>direcao;
                if (direcao == 'd')
                {
                    direcao='n';
                    sala = 4;
                }
                else if (direcao == 's')
                {
                    direcao='n';
                    sala = 1;
                }
            }
        }

        // SALA 3
        if (sala == 3)
        {
            cout << "sala 3 lv:" << lv << endl;

            cout << "Você pode retornar ou rotacionar as portas do labirinto no sentido horario quantas vezes gostaria de rotacionar? (digite r para rotacionar)" << endl;
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
            cout<<rotacao<<endl;
            }
            else if (direcao== 's')
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
            
            cout << "Opcoes: frente, tras, esquerda ou direita." << endl;
            cin >> direcao;
                if (direcao == 'w')
                {
                    direcao='n';
                    sala = 10;
                }

                else if (direcao == 'a')
                {
                  if (rotacao == 4)
                  {
                    direcao = 'n';
                    sala = 6;
                  } else {
                    direcao = 'n';
                    cout << "sua rotação não permite. rotação necessária: 6";
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
                    cout << "sua rotação não permite. rotação necessária: 1";
                  }


                }

            if (sala == 5) {
              std::cout << "sala 5";
              return 0;
            }

            if (sala == 6) {
              std::cout << "sala 6";
              return 0;
            }

            if (sala == 10) {
              std::cout << "sala 10";
              return 0;
            }



        }
    }

    cout << "Voce ganhou!!" << endl;

    return 0;
}
