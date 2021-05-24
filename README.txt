- Bibliotecas utilizadas:
    -> Graphviewer, utilizado para a visualização do mapa e dos grafos

- Instruções de utilização:
    1. Abrir a pasta do projeto como raiz no CLion.
    2. Correr o ficheiro CMakeLists.txt presente na pasta de raiz.
    3. Fazer build do projeto.
    4. Abrir a pasta cmake-build-debug na linha de comandos já que é aqui que se encontra o ficheiro executável.
    5. Correr o programa ao inserir "application.exe <args>" na linha de comandos. No caso de não serem passados nenhuns
    argumentos, será impresso no ecrã a seguinte mensagem que explica como utilizar o programa:

        Usage:
                application.exe view
                application.exe preprocess <node_id>
                application.exe astar <node_id1> <node_id2>
                application.exe orders <file_name>
                application.exe orders intime <file_name>

        Explicação dos argumentos:
            -> view: visualizar o mapa da região do Porto.
            -> preprocess <node_id>: visualizar o mapa após o processamento deste partindo de um vértice específico como
            raiz.
            -> astar <node_id1> <node_id2>: obter o caminho mais curto entre 2 vértices.
            -> orders <file_name>: processar as encomendas presentes num ficheiro que se deve encontrar na pasta
            "resources/data/orders", sem ter em conta a hora de preferência de entrega destas.
            -> orders intime <file_name>: faz o mesmo que o caso anterior mas desta vez é tido em conta as horas
            preferenciais de entrega.


