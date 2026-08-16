-- Last updated: 8/16/2026, 7:04:40 PM
# Write your MySQL query statement below
select Round(Count(distinct player_id)/ (select count(distinct player_id) from Activity),2)
as fraction
from Activity
where (player_id,Date_sub(event_date, interval 1 day)) in        
    (select player_id,min(event_date) as first_date from Activity
    group by player_id
    )


-- For each record in Activity:

-- event_date is when the player played.

-- DATE_SUB(event_date, INTERVAL 1 DAY) is the day before that play.

-- You’re comparing that day (the previous day) with the player’s first login date from the subquery.

-- So effectively, you’re checking:

-- “Is there an event such that the player’s current event happened exactly 1 day after their first login?”