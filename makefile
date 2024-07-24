
all: alunos

alunos: alunos.cpp aluno.cpp pessoa.cpp
	g++ alunos.cpp aluno.cpp pessoa.cpp -o alunos
