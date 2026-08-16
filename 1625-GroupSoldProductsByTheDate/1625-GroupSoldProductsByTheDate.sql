-- Last updated: 8/16/2026, 7:00:25 PM
# Write your MySQL query statement below
select sell_date, count(Distinct product) as num_sold, GROUP_CONCAT( DISTINCT product order by product ASC separator ',' ) as products
from activities
group by sell_date
order by sell_date ASC