**Master e main são a mesma coisa. Se vocês lerem master, e o nome da sua branch for main, considerem que eu estou falando da mesma coisa.**

Comando inicial:
```shell
git clone https://github.com/FlatbedOnline/GameProjectBCC
```

>[! IMPORTANTE]
>Lembre-se de dar `git pull` com frequência dentro do repositório, para você obter sempre a versão mais atualizada do código em que está trabalhando. Ficar com uma versão antiga pode resultar em problemas de merge. Pesquise mais sobre "how to solve git merge problems" se você tiver problemas na hora de dar push ou mergir branchs. 

---

Para adicionar arquivos ao stagging:
```shell
git add (nome-do-arquivo)
```
ou
```shell
git add . ///isso seleciona todos os arquivos da pasta atual
```

---

Para ver o estado atual dos códigos e suas alterações:
```shell
git log
```
Vocês utilizarão esse comando com frequência, principalmente pra ver se algo está no stagging ou commitado. Vocês também verão pra ver quem foi o imbecil que editou o código com algum erro grotesco, pois terá o nome de cada um que deu commit no repo.

---

Para fazer commit dos arquivos:

```shell
git commit -m "mensagem de commit"
```

Ou simplesmente
```shell
git commit
```
Cujo abrirá um editor de texto para que a mensagem de commit seja realizada mais detalhadamente.

---

Para enviar suas alterações para o github:

```shell
git push -u (nome-da-branch)
```

---

Para criar branches novas:

```shell
git checkout -b "nome-da-nova-branch"
```
Esse cria e muda para uma nova branch. o `-b` em especifico é o comando que cria a branch, enquanto o checkout é o comando que muda para a branch.

- `git checkout` também é usado para mudar branches, caso você queira voltar pra branch master(branch raiz) você utiliza o 
	```shell
	git checkout master ///ou qualquer outra branch que você queira trocar.
	```

---
**Tenha cuidado ao mesclar branches, principalmente ao mesclar com a master(ou main dependendo do nome), teste meticulosamente antes de dar push pro github. Não faça merda.**

Para mergir branches: 
```shell
git merge nome-da-branch ///se não der merge problems, irá mesclar com sucesso
```

***Como caralhos o github sabe qual branch eu exatamente quero mergir?***
	Resposta: Tudo depende de qual branch você está. Para mesclar sua branch ao main, você precisa ir pro main `git checkout main` e lá você chama o comando de mesclar a branch. O git vai entender algo do tipo:
	*"Mescle a branch em que eu estou, com a branch que eu escrevi no comando. A branch que eu estou é a que irá ser alterada e permanecerá."*

Se você já mesclou tudo certinho e não utilizará mais a branch que você criou para trabalhar separadamente da branch principal. Você pode excluí-la(caso queira e caso seja sensato) com o comando:
```shell
git branch -d nome-da-branch
```

Após tudo isso, você ainda terá que dar `git push`não esqueça que o comando push, é o que envia para o github todas as alterações feitas localmente, se você só mesclou as branches sem dar push depois, as mudanças só foram feitas localmente.

**via de regra, sempre deem push(para enviar as alterações) e pull(para resgatar alterações feitas pelos seus colegas e deixar o código atualizado) com frequência.**
