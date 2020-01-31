<h3 align="center"><img src="https://i.imgur.com/o8QXIco.png" alt="logo" height="100px"></h3>
<p align="center">The minimalist window manager.</p>

This project was previously a work of satire, going under a different name, however I have decided to continue the project as it seems functional and ready to be improved upon. [Click here if you're a little curious.](https://github.com/vardy/aphelia#satire)

---

This window manager is single-file and small binary with low resource consumption. Personally, I find it's useful for focused work where you aren't moving around too much and don't need multiple workspaces (it doesn't support them, obviously).

## Default key-binds

 * Push window backwards `Alt+a`
 * Pull window forward `Alt+s`
 * Kill window `Alt+q`
 * Open (Suckless) *Simple Terminal (st)* `Alt+Return`
 * Open *dmenu* `Alt+d`
 * Kill window manager `Alt+Backspace`
 * Move windows `Alt+Left Click`
 * Resize windows `Alt+Right Click`

New key-binds are added by editing `aphelia.c` and re-compiling. It's actually pretty self-explanatory as the code is quite repetetive. Couple copy-pastes, tops.

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

## Satire

[/r/unixporn](https://reddit.com/r/unixporn) is great but sometimes it can get overly-cutesy. This project was meant to have fun with that idea a bit.

Here is the repository before the [sanitising commit](https://github.com/vardy/aphelia/commit/6dec1ff943a81d5bffc9bf616c95fcb7109ef07b): https://github.com/vardy/aphelia/tree/01dc35684c14d09a4f9b760ce7bb6377fd40c8c2

Lobsters discussion of project: https://lobste.rs/s/bsjkg2/aphelia_light_single_file_minimalist.

Original screenshot used: https://i.imgur.com/dultOz8.png