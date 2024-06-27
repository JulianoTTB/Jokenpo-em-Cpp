#include <iostream>
#include <string>
#include <random>
bool running = true;
int jogador1;
int jogador2;
int computador1;
int computador2;
char modochar;
char ply1;
char ply2;
std::string jogadas[] = {"Pedra", "Papel", "Tesoura"};
std::string jogada1;
std::string jogada2;
std::string sair;
std::string modostr;
std::string jogador1Str;
std::string jogador2Str;
int mode;
int placarJogador1 = 0;
int placarJogador2 = 0;
int placarComputador1 = 0;
int placarComputador2 = 0;
int modo;

int menu(){

while (true){
  std::cout<< "Escolha o modo de jogo" << '\n';
  std::cout<< "0 - Regras" << '\n';
  std::cout<< "1 - PVP - (Jogador x Jogador)" << '\n';
  std::cout<< "2 - PVE - (Jogador x Computdor)" << '\n';
  std::cout<< "3 - EVE - (Computador x Computador)" << '\n';
  std::cin >> modochar;

 if (modochar == '0'){
  std::cout << "Cada um irá jogar Pedra, papel ou tesoura simultâneamente, e ganha quem jogar o elemento que ganha do elemento do oponente" << "\n";
  std::cout << "Papel ganha de pedra" << "\n";
  std::cout << "Pedra ganha de tesoura" << "\n";
  std::cout << "Tesoura ganha de papel" << "\n";
    }else if(modochar == '1' || modochar == '2' || modochar == '3'){
     modostr = (1, modochar); 
     mode = stoi(modostr);
     break;
    }else{
      std::cout << "Comando inválido! Tente novamente :)" << "\n";
    }

  }

 return mode;
}
/*
1 - Pedra
2 - Papel
3 - Tesoura
*/
int jogador1Jogando(){
 while (true) {
 std::cout << "Faça sua jogada jogador 1: (1- Pedra, 2 - Papel, 3 - Tesoura)" << '\n';
 std::cin >> ply1;
 if (ply1 == '1' || ply1 == '2' || ply1 == '3') {
      jogador1Str = (1, ply1);
      jogador1 = stoi(jogador1Str);
      break;
    } else{
      std:: cout << "Comando inválido. Tente novamente :)" << '\n';
    }
  } 
  return jogador1;
}


int jogador2Jogando(){
 while (true){
 std::cout << "Faça sua jogada jogador 2: (1- Pedra, 2 - Papel, 3 - Tesoura)" << '\n';
 std::cin >> ply2;
 if (ply2 == '1' || ply2 == '2' || ply2 == '3') {
      jogador2Str = (1, ply2);
      jogador2 = stoi(jogador2Str);
      break;
    } else{
      std:: cout << "Comando inválido. Tente novamente :)" << '\n';
    }
  } 
 return jogador2;
}


int computador1Jogando(){
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(1, 3);

 computador1 = dist(gen);
 return computador1;
}

int computador2Jogando(){
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(1, 3);

 computador2 = dist(gen);
 return computador2;
}

 void resultado(std::string jogada1, std::string jogada2){
 switch (modo){
    case 1:
     std::cout << jogada1 << "(jogador1) x " << jogada2 << "(jogador2)" << '\n';
     std::cout << "Placar: " << placarJogador1 << " x "  << placarJogador2 << "\n";
     break;
    case 2:
     std::cout << jogada1 << "(jogador) x " << jogada2 << "(Computador)" << '\n';
     std::cout << "Placar: " << placarJogador1 << " x "  << placarComputador1 << "\n";
     break;
    case 3:
     std::cout << jogada1 << "(Computador1) x " << jogada2 << "(Computador2)" << '\n';
     std::cout << "Placar: " << placarComputador1<< " x " << placarComputador2 << "\n";
     break;

  }

}

void placar(){
 switch (modo){
  case 1:
    //PVP
   if ((jogador1 == 1 && jogador2 == 3)||(jogador1 == 2 && jogador2 == 1) || (jogador1 == 3 && jogador2 == 2)){
        placarJogador1++;
        resultado(jogadas[jogador1 - 1], jogadas[jogador2 - 1]);
        std::cout << "Jogador 1 ganhou!!" << '\n';
      }else if (jogador1 == jogador2){
        resultado(jogadas[jogador1 - 1], jogadas[jogador2 - 1]);
        std::cout << "Empate!" << '\n';
      }else if ((jogador1 == 3 && jogador2 == 1) ||(jogador1 == 1 && jogador2 == 2)|| (jogador1 == 2 && jogador2 == 3)){
        placarJogador2++;
        resultado(jogadas[jogador1 -1], jogadas[jogador2 - 1]);
        std::cout << "Jogador2 ganhou!!!!" << '\n';
      }
    break;
  case 2:
    //PVE 
    if ((jogador1 == 1 && computador1 == 3)||(jogador1 == 2 && computador1 == 1) || (jogador1 == 3 && computador1 == 2)){
        placarJogador1++;
        resultado(jogadas[jogador1 - 1], jogadas[computador1 - 1]);
        std::cout << "Jogador ganhou!!" << '\n';
      }else if (jogador1 == computador1){
        resultado(jogadas[jogador1 - 1], jogadas[computador1 - 1]);
        std::cout << "Empate!" << '\n';
      }else if ((jogador1 == 3 && computador1 == 1) ||(jogador1 == 1 && computador1 == 2)|| (jogador1 == 2 && computador1 == 3)){
        placarComputador1++;
        resultado(jogadas[jogador1 -1], jogadas[computador1 - 1]);
        std::cout << "Computador ganhou!!!" << '\n';
      }

    break;
  case 3:
    //EVE
    if ((computador1 == 1 && computador2 == 3)||(computador1 == 2 && computador2 == 1) || (computador1 == 3 && computador2 == 2)){
        placarComputador1++;
        resultado(jogadas[computador1 - 1], jogadas[computador2 - 1]);
        std::cout << "Computador 1 ganhou!!" << '\n';
      }else if (computador1 == computador2){
        resultado(jogadas[computador1 - 1], jogadas[computador2 - 1]);
        std::cout << "Empate!" << '\n';
      }else if ((computador1 == 3 && computador2 == 1) ||(computador1 == 1 && computador2 == 2)|| (computador1 == 2 && computador2 == 3)){
        placarComputador2++;
        resultado(jogadas[computador1 - 1], jogadas[computador2 - 1]);
        std::cout << "Computador 2 ganhou!!!!" << '\n';
      }

     break;
  }

}


 bool sairFunc(std::string sair){
  while (true){
  std::cout << "Deseja sair do jogo?" << '\n';
  std::cin >> sair;
  if (sair == "Sim" || sair == "sim"){
    running = false;
   switch (modo){
    case 1:
     std::cout << "Placar final: " << placarJogador1 << " x " << placarJogador2 << '\n'; 
     break;
    case 2:
     std::cout << "Placar final: " << placarJogador1 << " x " << placarComputador1 << '\n'; 
     break;
    case 3:
     std::cout << "Placar final: " << placarComputador1 << " x " << placarComputador2 << '\n'; 
     break;
  }
   break;
  }else if (sair == "Não" || sair == "não" || sair == "Nao" || sair == "nao"){
      break;
  }else{
    std::cout << "Comando inválido. Tente novamente :)" << '\n';
  }
  }

  return running;
}


void run(){
 modo = menu();
while (running){

 switch (modo){
  case 1:
      //PVP
      jogador1 = jogador1Jogando();
      jogador2 = jogador2Jogando();
      placar();
      running = sairFunc(sair);
      break;
  case 2:
      //PVE
      jogador1 = jogador1Jogando();
      computador1 = computador1Jogando(); 
      placar();
      running = sairFunc(sair);
      break;
  case 3:
      //EVE
      computador1 = computador1Jogando();
      computador2 = computador2Jogando();
      placar();
      running = sairFunc(sair);
      break;
    }

  }

}




int main(){
  std::cout << "Bem vindo ao jogo Pedra, Papel ou Tesoura, ou Jokenpô ";
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(1, 3);
 // Roda o jogo
  run();
 // Quando o jogo termina agradece por ter jogado
 std::cout << "Obrigado por jogar o jogo";
 return 0;
}

