---
title:  Lista 1 - Treinamento Rede GNU/Linux
author: "Juliano Garcia de Oliveira Nº USP: 9277086"
geometry: margin=3cm
date: "26 de Janeiro, 2017"
---
###Resolução dos exercícios

1.
    a) ``` cd ../../../../var/lib/mysql/<nomeArquivo> ```

    b) Para acessar pelo caminho absoluto: ``` cd /usr/share/games/supertux/sounds/<nomeArquivo> ```. Relativamente: ``` cd ../supertux/sounds/<nomeArquivo> ```

    c) Para acessar o diretório raiz: ``` cd / ```. Uma vez no diretório raiz, não há diferença entre acessar relativamente ou absolutamente, a definição de "acessar absolutamente" é acessar relativamente ao diretório raiz.

2.
    a) A permissão para ambos os arquivos ficaria: ``` -rwx------ ```.

    b) A pasta ficaria com permissão ``` drwxrwxrwx ``` e os arquivos com permissão ``` -rwxrwxrwx ```.

    c) A pasta *www* ficaria com a permissão ``` drw-rw---- ```.

3. Usando as funcionalidades da tecla SysRq, que permite executar algumas operações na máquina, com certas combinações de teclas. Pra reiniciar é usado o ALT + SysRq + R , E , S , U , B . Cada uma dessas últimas letras se refere à uma operação diferente, pra garantir a integridade do sistema (interromper processos, dar *unmount* nas partições, etc).

4. O comando ``` touch ``` serve pra modificar a *timestamp* de um arquivo, e tem várias opções de como fazer isso (passando a data, só o último acesso, etc). Como o comando cria o arquivo quando ele não existe (a menos que se use uma *flag* específica), é bastante usado pra criar arquivos vazios. 
