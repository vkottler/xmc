<!--
    =====================================
    generator=datazen
    version=3.1.3
    hash=9785371b9d3171acb706d865fc31ddaa
    =====================================
-->

# xmc ([0.1.2](https://github.com/vkottler/xmc/releases/tag/0.1.2))

[![codecov](https://codecov.io/gh/vkottler/xmc/branch/master/graph/badge.svg)](https://codecov.io/gh/vkottler/xmc)
![Build Status](https://github.com/vkottler/xmc/actions/workflows/yambs-project.yml/badge.svg)

*A firmware project for Infineon XMC devices.*

## Workflow

Install [vmklib](https://github.com/vkottler/vmklib) such that you can
`mk --version` (a `pip install vmklib` to your desired Python environment is
all that's needed).

From a fresh checkout:

```
git submodule update --init
mk dz-sync
mk download-toolchains
mk g
```

This should result in fully compiled code that you can now use or add to.


### Generating Interfaces

Structs and enumerations can be defined for
[ifgen](https://github.com/vkottler/ifgen) which can then generate C++ source
code into the project.

Generating configurations based on an
[SVD](https://github.com/vkottler/ifgen/tree/master/ifgen/data/svd) file:

```
mk ifgen-svd-XMC4700
```

Generating code from an `ifgen.yaml` in the root directory of the project:

```
mk ifgen
```
