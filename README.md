# Pomodoro (chrono)

Un minuteur Pomodoro minimaliste en C : un compte à rebours coloré dans le
terminal, puis un écran de fin qui clignote jusqu'à ce que tu appuies sur
Espace.

![demo du chrono](docs/demo.gif)

## Compilation

```sh
make
```

ou directement :

```sh
cc src/chrono.c src/conio_new.c -I header -o chrono
```

## Utilisation

```sh
./chrono <heures> <minutes> <secondes>
```

| Exemple            | Effet                      |
|--------------------|----------------------------|
| `./chrono 0 25 0`  | une session de 25 minutes  |
| `./chrono 0 5 0`   | une pause de 5 minutes     |
| `./chrono 1 30 0`  | 1 h 30                     |

Les trois arguments sont des entiers positifs. Sans arguments valides, le
programme affiche l'usage et quitte avec le code 1.

## Contrôles

- **Espace** : quitter l'écran de fin une fois le temps écoulé.

## Fichiers

```
.
├── header/chrono.h     prototypes et structure principale
├── src/chrono.c        boucle du compte à rebours et écran de fin
├── src/conio_new.c     kbhit() / getch() : lecture clavier non bloquante (termios)
└── Makefile
```

## Fonctionnement

Le programme redessine le cadre chaque seconde avec des séquences ANSI
(effacement d'écran et couleurs). Quand la cible est atteinte, il passe le
terminal en mode non canonique pour détecter la touche Espace sans bloquer,
et fait défiler les couleurs du cadre toutes les deux secondes.
