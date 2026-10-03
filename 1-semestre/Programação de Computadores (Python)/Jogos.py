import random
import time

# Jogo 1
def tigrinho():
    print("\nAbrindo 🐯 - Tigrinho de Las Venturas")

    simbolos = ["🍋 Limão", "🍒 Cereja", "🍉 Melancia"]

    print("\n🐯 - Tigrinho de Las Venturas - 🐯")

    while True:
        input("pressione Enter para começar") 

        print("\nGirando...")
        time.sleep(1)

        # Caixas onde serão rodadas os simbolos
        slot1 = random.choice(simbolos)
        print(slot1)
        time.sleep(1)

        slot2 = random.choice(simbolos)
        print(slot2)
        time.sleep(1)
        
        slot3 = random.choice(simbolos)
        print(slot3)
        time.sleep(1)

        # Resultado do jogo
        print("\nResultado:")
        print("[", slot1, "|", slot2, "|", slot3, "]")

        # Caso as 3 caixas tenham os 3 simbolos iguais, o jogador vence
        if slot1 == slot2 == slot3:
            print("\n 🎉 GANHOU!!! AGORA GASTE O PREMIO CONOSCO NOVAMENTE E GANHE MAIS DINHEIRO! ou talvez não...")
        
        # Caso as caixas não sejam iguais, o jogador perde e o codigo pergunta se quer jogar novamente.
        else:
            print("\n😭 Perdeu, faz o L agora.")
        jogar = input("\nQuer apostar a alma da sua mãe de novo? (s/n): ")
        if jogar == "n":
            print("Obrigado por jogar! Aproveite o dinheiro do trafico...")
            break

# Jogo 2

def boss_fight():

    print("\nAbrindo 🐲 - Boss Fight")

    vida_dragao = 50
    dados_restantes = 13

    print("=" * 40)
    print(" BOSS FIGHT: O DRAGÃO ")
    print("=" * 40)
    print("Você tem 13 dados para causar 50 de dano!")
    print("Cada dado causa entre 1 e 6 de dano.")
    print("Derrote o dragão antes dos dados acabarem!")
    print("=" * 40)

    input("\nPressione ENTER para começar...")

    while vida_dragao > 0 and dados_restantes > 0:

        print("\n" + "-" * 40)
        print(f" Vida do Dragão: {vida_dragao}")
        print(f" Dados restantes: {dados_restantes}")
        print("-" * 40)

        escolha = input("Pressione ENTER para rolar o dado...")

        dano = random.randint(1, 6)

        print("\nRolando dado...")
        time.sleep(1)

        print(f" Você causou {dano} de dano!")

        vida_dragao -= dano
        dados_restantes -= 1

        if vida_dragao > 0:
            print(f" O dragão ainda está vivo com {vida_dragao} de vida!")
        else:
            print("\n VOCÊ MATOU O DRAGÃO!")
            print(" Vitória épica!")

    if vida_dragao > 0:
        print("\n Seus dados acabaram!")
        print(f"O dragão sobreviveu com {vida_dragao} de vida...")
        print(" GAME OVER")

# Menu Principal
while True:
    print("\n===== MENU DE JOGOS =====")
    print("1 - Tigrinho de Las Venturas")
    print("2 - Boss Fight")
    print("0 - Sair")

    escolha = input("\nEscolha um jogo: ")

    if escolha == "1":
        tigrinho()

    elif escolha == "2":
        boss_fight()

    elif escolha == "0":
        print("Saindo...")
        break


    else:
        print("Opção inválida!")