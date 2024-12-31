select A.ID as ID, B.FISH_NAME as FISH_NAME, A.LENGTH as LENGTH
from FISH_INFO A, FISH_NAME_INFO B
where A.FISH_TYPE = B.FISH_TYPE
and (A.FISH_TYPE, LENGTH) in
(
select FISH_TYPE, max(length)
from FISH_INFO
group by FISH_TYPE
)
order by A.ID