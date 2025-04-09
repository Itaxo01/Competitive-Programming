### Centróides
 * Árvore balanceada em relação à sua "massa"
 * Cada árvore possui um ou dois(nesse caso são equivalentes) centróides
 * Sua definição é que todas as subárvores formadas pela remoção do centróide possuem uma quantidade de vértices menor ou igual à metade da árvore original.

#### Características e Execução
###### Build nlog(n):
* Inicia com uma subárvore. 
* Roda uma dfs a partir de algum nó desta árvore, e guarda a quantidade de nós a partir de determinado vértice (assim só precisa de uma dfs para cada subárvore).
* Enquanto existir algum vizinho do nó que
possua mais da metade dos vértices, navegue para ele (é fácil de perceber que haverá só um).
* Quando acabar, o vértice em questão será a raiz do 
respectivo centróide.
* Remova o vértice da dfs (Crie um vetor de removidos e marque como true), e para cada vizinho deste nó, busque seu centróide repetindo este processo.
* Cada vértice navegado após achar o centróide terá um pushback(u) em seus ancestróides.

* É nlog(n) pois, apesar de a dfs precisar ser executada n vezes (e ter custo n², em teoria), o tamanho da árvore cai pela metade a cada execução.



update(u) log(n);
* Troca a cor do vértice u, e para cada ancestróide de u, notifica o mesmo para fazer um ancestor[k]->min = min(ancestor[k]->min, ancestor[k]->dist[u]);

dist(u) log(n);
* Para cada ancestróide de u, dist = min(dist, ancestor[k]->min);