-- Last updated: 8/16/2026, 7:05:03 PM
# Write your MySQL query statement below
# Write your MySQL query statement below
select product_name,year,price 
from Sales s
join Product p 
on s.product_id=p.product_id;