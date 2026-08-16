-- Last updated: 8/16/2026, 7:05:09 PM
# Write your MySQL query statement below
select actor_id,director_id from ActorDirector
group by actor_id,director_id
having count(timestamp)>=3