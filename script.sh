#PBS -l nodes=4:ppn=1,mem=1gb,walltime=00:02:00
#PBS -M yd.hernandez10@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio30

module load anaconda/python3
cd /hpcfs/home/fisi4028/yd.hernandez10 # este es el directorio desde donde se ejecuto qsub

rm -f *.txt *.png walk.x
export OMP_NUM_THREADS=1
gcc -fopenmp walk.c -o walk.x
./walk.x > datosSeriales.txt
rm walk.x
export OMP_NUM_THREADS=7
gcc -fopenmp walk.c -o walk.x
./walk.x > datosParalelos.txt

python graficando.py

export OMP_NUM_THREADS=7
gcc -fopenmp advectiveYvan.c -o Yvan.x
./Yvan.x > datos1Paralelos.txt

