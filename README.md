libewmh
========

An xcb wrapper library for ICCCM and EWMH.

Build
-----

```sh
$ make
```
This command will create directory `build` in repository root and the output will be saved there.

Test
-----

```sh
$ cd tests
$ make
$ make run WINDOW_ID=(YOUR WINDOW ID IN HEX)
```

Install
-------

```sh
$ make install
```

Currently this command installs only to `/usr/lib/`.
