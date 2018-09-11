#define TAG_RESULT 0

#define TAG_ASK_FOR_JOB 1
#define TAG_JOB_DATA 2
#define TAG_STOP 3


void master () {

    MPI_Status stat, stat2;

    while ( /
        MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TYPE, MPI_COMM_WORLD, &stat);


        int slave_rank = stat.MPI_SOURCE;


        if (stat.MPI_TAG == TAG_ASK_FOR_JOB) {

            MPI_Recv(buff, slave_rank, TAG_ASK_FOR_JOB, MPI_COMM_WORLD, &stat2);

            if () {


                job = 
                MPI_Send(msg_buffer, slave_rank, TAG_JOB_DATA, MPI_COMM_WORLD);

            } else {


                MPI_Send ( , slave_rank , TAG_STOP , MPI_COMM_WORLD);
            }
        } else {


            MPI_Recv( result_data_buffer , slave_rank , TAG_RESULT, MPI_COMM_WORLD , & stat2 );
           
        }
    }
}

void slave () {
    int stopped = 0;
    MPI_Status stat , stat2 ;
    do {


        MPI_Send (  0 , TAG_ASK_FOR_JOB , MPI_COMM_WORLD ) ;
        MPI_Probe (0 , , MPI_COMM_WORLD , & stat ) ;
        if ( stat . MPI_TAG == TAG_JOB_DATA ) {


            MPI_Recv ( msg_buffer , 0, TAG_JOB_DATA , MPI_COMM_WORLD , & stat2 ) ;

           


            MPI_Send ( result_buffer  , 0 , TAG_RESULT, MPI_COMM_WORLD);
        } else {
           
            MPI_Recv ( 0, TAG_STOP , MPI_COMM_WORLD , &stat2);
            stopped = 1;
        }
    } while (stopped == 0);
}


int main(int argc, char **argv) {

    int rank;

    MPI_Init(&argc , & argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        master () ;
    } else {
        slave () ;
    }

    MPI_Finalize () ;
}
