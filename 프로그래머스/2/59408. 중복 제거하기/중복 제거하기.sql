select count(*) as count from
(select name, count(*)
from animal_ins
where name is not null
group by name
 )