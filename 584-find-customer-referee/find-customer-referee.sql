select c1.name from customer c1 join customer c2 on c1.id=c2.id where c1.referee_id!=2 or c2.referee_id is NULL;
