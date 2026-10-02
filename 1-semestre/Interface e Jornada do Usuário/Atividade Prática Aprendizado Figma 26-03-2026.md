# Fase 1: Estrutura Base e Componentes

Criação do Grid: Configurar um Grid (Desktop – px? Pesquise resolução média de sites) com colunas de 12.

Criação do Menu (Componente):

Criar uma Navbar com Logo (à esquerda) e Links (Home, Serviços, Portfólio, Sobre, Contato).

Transformar a Navbar em Component.

Desafio: Criar uma Variant chamada "Active". Na Variant "Active", alterar a cor do texto do link correspondente (ex: "Home" em azul). No protótipo, ao clicar em "Serviços", a Navbar deve trocar para a Variant onde "Serviços" está ativo.

# Fase 2: Conteúdo das Páginas

Criar 5 Frames: Nomeá-los como: Home, Servicos, Portfolio, Sobre, Contato.

Auto Layout:

Construir os Cards de Serviços usando Auto Layout (Vertical + Horizontal). Os cards devem ter tamanho fixo de largura, mas altura automática conforme o texto.

Na página de Portfólio, criar uma grade de imagens usando Auto Layout Wrap (ou Grid).

# Fase 3: O Grande Desafio - Banner Carrossel Automático

Esta é a parte mais técnica para estimular a aprendizagem avançada do Prototype.

Setup: Na página Home, crie um componente de "Banner". Dentro dele, coloque 3 imagens empilhadas.

Variants:

Crie 3 Variants para o componente Banner: Slide 1, Slide 2, Slide 3.

Em cada variant, mova a imagem correspondente para o topo (visível) e as outras atrás.

Interação Automática:

Vá para a aba Prototype.

Conecte Slide 1 -> Slide 2 usando After Delay (3000ms) e animação Smart Animate.

Conecte Slide 2 -> Slide 3 com After Delay (3000ms).

Conecte Slide 3 -> Slide 1 com After Delay (3000ms) para criar o loop infinito.

#Fase 4: Interatividade Total - Menu Funcional

Agora vamos ligar as 5 páginas pelo menu:

Selecione o Frame Home.

No menu (componente), selecione o texto "Serviços".

Arraste o noodle (bolinha azul) até o Frame Servicos.

Na inspeção, escolha a interação: On Click -> Navigate to -> Smart Animate.

Repita para todos os links do menu, conectando cada texto ao seu respectivo frame.

Desafio Extra: Ao navegar, faça a Navbar trocar de Variant para mostrar qual página o usuário está (dica: use Change to junto com Navigate to).

Compartilhar o link para visualização do projeto

https://www.figma.com/proto/DP4KObwK1jCkYNoo7EfMxa/Untitled?node-id=0-1&t=bueeapf9Lv8hnyxK-1

