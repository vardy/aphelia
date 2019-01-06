<h3 align="center"><img src="https://i.imgur.com/o8QXIco.png" alt="logo" height="100px"></h3>
<p align="center">The minimalist window manager.</p>

This project was previously a work of satire, going under a different name, however I have decided to continue the project as it seems functional and ready to be improved upon.

This window manager is single-file and a super small binary with low resource consumption. Personally, I find it's useful for focused work where you aren't moving around too much and don't need multiple workspaces (it doesn't support them, obviously).

## Default key-binds

 * Push window backwards `Alt+a`
 * Pull window forward `Alt+s`
 * Kill window `Alt+q`
 * Open (Suckless) *Simple Terminal (st)* `Alt+Return`
 * Open *dmenu* `Alt+d`
 * Kill window manager `Alt+Backspace`
 * Move windows `Alt+Left Click`
 * Resize windows `Alt+Right Click`

New key-binds are currently added by editing `aphelia.c` and re-compiling. It's actually pretty self-explanatory as the code is quite repetetive. Couple copy-pastes, tops.

## Installation

Install:
```
sudo make install
```

Uninstall:
```
sudo make clean
```

Reinstall:
```
sudo make reinstall
```

## Contributions

Fork this repo and issue pull requests to contribute. I'll look at them as soon as I am able! 
