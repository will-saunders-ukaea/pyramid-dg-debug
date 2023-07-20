## Running

The following fails (sequential is fine),
```
mpirun -n 8 ./Foo conditions.xml tet_pyr.xml
```

with example backtrace in `backtrace.txt`.


## Mesh Re-creation

```
# Creates tet_pyr.msh, uses gmsh python bindings.
python3 tet_pyr_face.py
# Creates tet_pyr.xml from tet_pyr.msh
bash mesh_gen.sh tet_pyr.msh
```


