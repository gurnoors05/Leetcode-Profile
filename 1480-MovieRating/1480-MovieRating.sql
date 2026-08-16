-- Last updated: 8/16/2026, 7:01:36 PM
# Write your MySQL query statement below
(select name as results
from MovieRating join
Users on Users.user_id=MovieRating.user_id
group by name
order by count(*) desc,name
limit 1
)

UNION ALL

(select title as results
from MovieRating join Movies on
MovieRating.movie_id=Movies.movie_id
where MovieRating.created_at BETWEEN '2020-02-01' AND '2020-02-29'
group by title 
order by avg(rating) desc,title
limit 1
)