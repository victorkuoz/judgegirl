#include <stdlib.h>
#include "reservation.h"

Reservation *make_reservation ( int nP, int StartTime, int EndTime ){
     Reservation *reservation = (Reservation*) malloc(sizeof(Reservation));
     reservation->nP = nP;
     reservation->StartTime = StartTime;
     reservation->EndTime = EndTime;
     reservation->next = NULL;
     return reservation;
}

int ReserveRoom(RoomStatus List[], int nR, int nP, int StartTime, int EndTime){
     for ( int k = 0; k < nR; k++ ){
          if ( List[k].capacity >= nP ){
               if ( List[k].reservation == NULL ){
                    List[k].reservation = make_reservation( nP, StartTime, EndTime );
                    return 1;
               }

               if ( EndTime <= List[k].reservation->StartTime ){
                    Reservation *temp = make_reservation( nP, StartTime, EndTime );
                    temp->next = List[k].reservation;
                    List[k].reservation = temp;
                    return 1;
               }

               Reservation *cur = List[k].reservation;
               while ( cur->EndTime <= StartTime ){
                    if ( cur->next == NULL ){
                         cur->next = make_reservation( nP, StartTime, EndTime );
                         return 1;
                    }
                    if ( EndTime <= cur->next->StartTime ){
                         Reservation *temp = make_reservation( nP, StartTime, EndTime );
                         temp->next = cur->next;
                         cur->next = temp;
                         return 1;
                    }
                    cur = cur->next;
               }
          }
     }
     return 0;
}

