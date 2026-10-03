#definindo as variaveis e listas
quartos = list(range(100, 106)) + list(range(200, 206)) + list(range( 300, 306))
disponiveis = ['102','200','204','301','304','303','305']
indisponiveis = ['100','101','103','104','105','201','202','203','205','300','302']
cardapio1 = {'X-Tudo': 'R$20','X-Salada':'R$17','Fritas': 'R$12','Cachorro Quente':'R$15', 'Fatia de Pizza': 'R$8'}
cardapio2 = {'Suco de Laranja': 'R$8', 'Suco de Uva': 'R$8', 'Achocolatado': 'R$5', 'Kaiser': "R$6", 'Coca Cola': 'R$8'}
limpeza = ['101', '103', '104', '203', '300',]
diaria = 175
indi = '100'
limpar = '104'
sim = ('s','S','sim','SIM','si','Si','sIM','SiM','SIm','SS','ss','Ss','sS','Y','y','Yes','yes') #eu juro que foi necessario fazer isso
nao = ('n','N','não','NÃO','nao','NAO','Nao','Não','nAo','nÃo','naO','nãO','NAo','NÃo','nAO','nÃO','na','nã','Na','Nã','nA','nÃ','ñ','Ñ','No','NO','no')

while True: #loopando o menu
    print("\n Hospedaria Los Santos")
    print("1 - Quartos Disponíveis")
    print("2 - Quartos Indisponíveis")
    print("3 - Limpeza de Quartos")
    print("4 - Serviço de Quarto")
    print("5 - Todos os Quartos")
    print("0 - Fechar")

    escolha = input("\nEscolha: ") #pedindo um dos 6 numeros para o usuário

    if escolha == "1": #mostrando o menu de quartos disponiveis
        print("\nQuartos disponíveis: ", disponiveis)
        print("Preço da diaria:R$ ", diaria)

        cancel1 = input("\nDeseja continuar alugando um quarto? s/n: ") #confirmando se o usuário não quer voltar para o menu
        if cancel1 in nao:
            print("\nVoltando ao menu") #voltando o usuário para o menu

        else: #sistema do aluguel de quartos
            indi = input("\nDigite o número do quarto para alugar: ")
            if indi in disponiveis:
                indisponiveis.append(indi)
                disponiveis.remove(indi)
                print("\nO quarto",indi, "foi alugado por R$:",diaria)

            else: #mensagem de erro caso o usuário escreva algo errado e voltando ele para o menu
                print("\nOcorreu um erro, tente novamente")

    elif escolha == "2": #mostrando o menu de quartos indisponiveis
        print("\nQuartos indisponíveis: ", indisponiveis)
        print("Quartos recém alugados: ", indi)
        print("Quartos que precisam de limpeza: ", limpeza)
        print("Quartos recém adicionados a lista de limpeza: ", limpar)

        cancel2 = input("\nDeseja adicionar algum quarto a lista de disponíveis? s/n: ") #confirmando se o usuário não quer voltar para o menu
        if cancel2 in sim:
            disp = input("\nDigite o número do quarto que está recém disponível: ")
            if disp in indisponiveis:
                disponiveis.append(disp)
                indisponiveis.remove(disp)
                print("\nO quarto",disp,"foi adicionado a lista de quartos disponíveis para alugar.")

        else:
            print("\nVoltando ao menu") #voltando o usuário para o menu

    elif escolha == "3": #mostrando o menu de limpeza de quartos
        cancel3 = input("\nDeseja adicionar um quarto para a lista de limpeza? s/n: ") #confirmando se o usuário não quer voltar para o menu
        if cancel3 in sim:
            print("\n",indisponiveis) 
            limpar = input("Qual quarto precisa de limpeza: ") #sistema sistema de limpeza quartos

            if limpar in indisponiveis:    
                limpeza.append(limpar)
                print("\nOs quartos: ", limpeza, "serão limpos" )
                print("Quartos recem adicionados a lista de limpeza: ", limpar)

            else: #mensagem de erro caso o usuário escreva algo errado e voltando ele para o menu
                print("\nOcorreu um erro, tente novamente")

        else: #voltando o usuário para o menu
            print("\nVoltando ao menu") 

    elif escolha == "4": #mostrando o menu de serviço de quarto
        print("\nQuartos disponiveis para o serviço de quarto: ", indisponiveis)
        cancel4 = input("\nDeseja continuar a pedir o serviço de quarto? s/n: ") #confirmando se o usuário não quer voltar para o menu
        if cancel4 in sim:
            servi = input("\nQual quarto precisa de serviço de quarto: ") #sistema de serviço de quarto
            if servi in indisponiveis:
                for chave, valor in cardapio1.items():
                    print("\n",chave,":", valor)
                comida = input("\nEscolha a refeição: ") 
                if comida in cardapio1:
                    print("\nA refeição escolhida foi:", comida)

                    for chave, valor in cardapio2.items():
                        print("\n",chave, ":", valor)
                    bebida = input("\nEscolha a bebida: ")
                    if bebida in cardapio2:
                        print("\nA bebida escolhida foi: ", bebida)

                        print(comida,"e", bebida, "serão levadas até o quarto:", servi, "em aproximadamente 10 minutos")

                    else: #mensagem de erro caso o usuário escreva algo errado e voltando ele para o menu
                        print("\nOcorreu um erro, tente novamente")

                else: #mensagem de erro caso o usuário escreva algo errado e voltando ele para o menu
                    print("\nOcorreu um erro, tente novamente")

            else: #mensagem de erro caso o usuário escreva algo errado e voltando ele para o menu
                print("\nOcorreu um erro, tente novamente")

        else: #voltando o usuário para o menu
            print("\nVoltando ao menu")

    elif escolha == "5": #mostrando o menu de quartos
        print(quartos)
        cancel5 = input("\nAperte a tecla ENTER para voltar ao menu: ") #confirmando se o usuário quer voltar para o menu

    elif escolha == "0": #mostrando o menu de fechar o programa
        cancel0 = input("\nTem certeza? s/n: ") #confirmando se o usuário não quer voltar para o menu
        if cancel0 in sim:
            print("\nEncerrando...")
            break

        else: #voltando o usuário para o menu
            print("\nVoltando ao menu")

    else: #mensagem de erro caso o usuário escreva algo errado e voltando ele para o menu
        print("\nOpção invalida")