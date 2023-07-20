## Running

The following fails (sequential is fine),
```
mpirun -n 8 ./Foo conditions.xml tet_pyr.xml
```

with example backtrace in `backtrace.txt`.

# Environment

Nektar version: 5.3.0, `2e0fb86da236e7e5a3590fcf5e0f608bd8490945`.
See modules-loaded for dependencies.

## Mesh Re-creation

```
# Creates tet_pyr.msh, uses gmsh python bindings.
python3 tet_pyr_face.py
# Creates tet_pyr.xml from tet_pyr.msh
bash mesh_gen.sh tet_pyr.msh
```


