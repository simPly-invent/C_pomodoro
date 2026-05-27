# Pomodoro (chrono)

Un minuteur Pomodoro tout simple en C, qui affiche un compte à rebours coloré dans le terminal.

## Description

Le programme prend une durée en **heures, minutes et secondes**, puis affiche
un chronomètre qui défile jusqu'à atteindre la cible. Une fois le temps écoulé,
un écran de fin clignotant t'invite à appuyer sur **Espace** pour quitter.

## Compilation

```bash
make
```

ou directement :

```bash
gcc src/chrono.c -o chrono
```

## Utilisation

```bash
./chrono <heures> <minutes> <secondes>
```

### Exemple

```bash
./chrono 0 25 0
```

Lance un chrono de 25 minutes.

## Contrôles

- **Espace** : quitter l'écran de fin une fois le temps écoulé.

## Notes

- Les trois arguments doivent être des nombres entiers positifs.
- Si les arguments sont manquants ou invalides, le programme affiche :
