select food_type, REST_ID, REST_NAME, FAVORITES
from REST_INFO
where (food_type, favorites) in
(
select food_type, max(favorites) as FAVORITES
from REST_INFO
group by food_type
)
order by food_type desc