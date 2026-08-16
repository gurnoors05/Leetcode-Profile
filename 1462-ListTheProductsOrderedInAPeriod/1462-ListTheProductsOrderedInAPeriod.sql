-- Last updated: 8/16/2026, 7:01:52 PM
# Write your MySQL query statement below
select p.product_name,sum(o.unit) as unit
from Products p
join Orders o
ON p.product_id = o.product_id
WHERE o.order_date LIKE "2020-02-%"
group by p.product_id
having unit >=100