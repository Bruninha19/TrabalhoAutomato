Instalando o MinGW + C no VScode

🧱 PARTE 1 — Instalando o MinGW

🔹 1. Baixar
Acesse o site do MinGW
Clique em Download Installer (mingw-get-setup.exe)

🔹 2. Instalar
Quando abrir o instalador:
Clique em Install
Escolha o diretório padrão:
C:\MinGW
Clique em Continue

🔹 3. Selecionar pacotes (IMPORTANTE)
Vai abrir o MinGW Installation Manager:
✔ Marque:
mingw32-base
mingw32-gcc-g++
👉 Como marcar:
Clique com botão direito → Mark for Installation
Depois:
Menu Installation → Apply Changes → Apply

🔧 PARTE 2 — Configurar o PATH

🔹 1. Copiar caminho
C:\MinGW\bin

🔹 2. Adicionar no sistema
Aperta Win + S
Digita: variáveis de ambiente
Clique em:
 👉 Editar variáveis de ambiente do sistema
Agora:
Clique em Variáveis de Ambiente
Em Variáveis do sistema, selecione:
 👉 Path
Clique em Editar
Clique em Novo
Cole:
C:\MinGW\bin
Clique em OK em tudo

🔹 3. Testar
Abra o Prompt de Comando e digite:
gcc --version
👉 Se aparecer versão → ✔ tudo certo

💻 PARTE 3 — Configurar no Visual Studio Code

🔹 1. Instalar VS Code
Baixe e instale normalmente

🔹 2. Instalar extensão C/C++
Abra o VS Code
Vá em Extensões (Ctrl+Shift+X)
Procure:
 👉 C/C++ (Microsoft)
Clique em Instalar

🔹 3. Criar projeto
Crie uma pasta:
automato-c
Abra no VS Code:
 👉 File → Open Folder
Crie um arquivo:
automato.c


▶️ PARTE 4 — Rodar o código

🔹 Método simples (melhor pra você agora)
No VS Code:
Vá em Terminal → New Terminal
Digite:
gcc automato.c -o automato
Depois:
automato

⚠️ ERROS COMUNS (muito importante)
❌ gcc não reconhecido
✔ Corrige:
PATH errado
reiniciar terminal

❌ comando “automato” não funciona
✔ Use:
.\automato

#Teste

Sugiro que teste as palavras: a, b, ab, aab, aabb, abb

![Autômato](automato.png)
