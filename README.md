<div align="center">

# Minishell 2

**Mon shell, en mieux : séparateurs et redirections.**

<img alt="C" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white"/> <img alt="Make" src="https://img.shields.io/badge/Make-427819?style=for-the-badge&logo=gnu&logoColor=white"/> <img alt="Unix" src="https://img.shields.io/badge/Unix-333333?style=for-the-badge&logo=linux&logoColor=white"/>

<sub>Projet solo · 2023</sub>

</div>

<br/>

<p align="center"><img src=".github/assets/minishell2.gif" alt="Minishell 2" width="820"/></p>

## En deux mots

La suite de [Minishell 1](https://github.com/Wilson-Epitech/minishell1). On garde tout ce qu'il savait faire, et on ajoute de quoi enchaîner les commandes et rediriger leur sortie.

## Ce que ça fait

- Séparateur `;` pour enchaîner les commandes
- Redirections de sortie `>` et `>>`
- Builtins `cd`, `env`, `setenv`, `unsetenv`, `exit`
- Recherche des binaires dans le `PATH`, messages d'erreur à la tcsh

## Sous le capot

La ligne est d'abord découpée sur les `;`, puis chaque commande est analysée pour repérer les redirections. On ouvre le fichier cible, on redirige la sortie avec `dup2` dans le fils, puis on `execve`.

## Lancer le projet

```bash
make
./mysh
```
