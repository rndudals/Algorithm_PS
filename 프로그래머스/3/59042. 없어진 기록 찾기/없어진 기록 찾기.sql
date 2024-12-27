select O.ANIMAL_ID, O.NAME
from ANIMAL_INS I 
right join ANIMAL_OUTS O
on I.ANIMAL_ID = O.ANIMAL_ID
where I.DATETIME is null
order by O.ANIMAL_ID, O.NAME