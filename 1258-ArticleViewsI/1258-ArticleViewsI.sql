-- Last updated: 8/16/2026, 7:04:11 PM
# Write your MySQL query statement below
select distinct author_id as id 
from Views
where
author_id=viewer_id
order by id