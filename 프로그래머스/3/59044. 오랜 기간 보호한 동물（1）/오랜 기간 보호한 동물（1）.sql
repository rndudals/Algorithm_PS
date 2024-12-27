select NAME, DATETIME
from
(
select I.NAME, I.DATETIME
from ANIMAL_INS I
left join ANIMAL_OUTS O
on I.ANIMAL_ID = O.ANIMAL_ID
where O.DATETIME is null
order by I.DATETIME
)
where rownum<=3