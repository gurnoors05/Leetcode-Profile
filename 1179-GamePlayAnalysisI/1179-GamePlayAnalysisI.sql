-- Last updated: 8/16/2026, 7:04:43 PM
# Write your MySQL query statement below
select player_id,min(event_date) as first_login
from Activity
group by player_id