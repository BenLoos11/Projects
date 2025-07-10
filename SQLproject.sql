--Question 1
SELECT CONVERT(VARCHAR, GETDATE() - 7, 23) AS [ANSI Week Old Date];
--Question 2 ?
DECLARE @Data VARCHAR(100) = 'Before software can be reusable it first has to be usable.'
SELECT 
    '1' + ' ' + 
    SUBSTRING(@Data, CHARINDEX('first ', @Data), LEN(@Data)) AS Result;
--Question 3
SELECT 
    r.RegionDescription, 
    t.TerritoryDescription
FROM 
    Region r
JOIN 
    Territories t ON r.RegionID = t.RegionID
ORDER BY 
    r.RegionDescription, t.TerritoryDescription;
--Question 4 
SELECT 
    p.ProductName, 
    CEILING((p.ReorderLevel * 1.25) - (p.UnitsInStock + p.UnitsOnOrder)) AS [Units to Order]
FROM 
    Products p
WHERE 
    (p.UnitsInStock + p.UnitsOnOrder) < p.ReorderLevel;
-- Question 5 
SELECT 
    c.CategoryName AS [Category Name],
    p.ProductName AS [Product Name], 
    p.UnitPrice AS [Unit Price]
FROM 
    Products p
JOIN 
    Categories c ON p.CategoryID = c.CategoryID
WHERE 
    p.UnitPrice > (SELECT AVG(UnitPrice) FROM Products WHERE CategoryID = p.CategoryID)
ORDER BY 
    c.CategoryName, p.ProductName;
--Question 6 
SELECT 
    t.TerritoryDescription,
    COALESCE(e.Lastname + ', ' + e.FirstName, 'No Employees') AS EmployeeName
FROM 
    Territories t
LEFT JOIN 
    EmployeeTerritories et ON t.TerritoryID = et.TerritoryID
LEFT JOIN 
    Employees e ON et.EmployeeID = e.EmployeeID
ORDER BY 
    t.TerritoryDescription, EmployeeName;
--Question 7
SELECT 
    COUNT(et.EmployeeID) AS EmployeeCount, 
    t.TerritoryDescription
FROM 
    Territories t
LEFT JOIN 
    EmployeeTerritories et ON t.TerritoryID = et.TerritoryID
GROUP BY 
    t.TerritoryDescription
ORDER BY 
    EmployeeCount DESC, t.TerritoryDescription;
--Question 8 
SELECT 
     COUNT(et.EmployeeID) AS EmployeeCount,
	 r.RegionDescription
FROM 
    Region r
LEFT JOIN 
    Territories t ON r.RegionID = t.RegionID
LEFT JOIN 
    EmployeeTerritories et ON t.TerritoryID = et.TerritoryID
GROUP BY 
    r.RegionDescription
ORDER BY 
    EmployeeCount DESC, r.RegionDescription;
--Question 9 
SELECT 
    supervisor.FirstName + ' ' + supervisor.LastName AS SupervisorName,
    COUNT(e.EmployeeID) AS EmployeeCount
FROM 
    Employees e
JOIN 
    Employees supervisor ON e.ReportsTo = supervisor.EmployeeID
GROUP BY 
    supervisor.EmployeeID, supervisor.FirstName, supervisor.LastName
HAVING 
    COUNT(e.EmployeeID) >= 4;

--Question 10 

WITH TerritoryEmployeeCounts AS (
    SELECT  
	COUNT(et.EmployeeID) AS EmployeeCount,
        t.TerritoryDescription
    FROM 
        Territories t
    LEFT JOIN 
        EmployeeTerritories et ON t.TerritoryID = et.TerritoryID
    GROUP BY 
        t.TerritoryDescription
)
SELECT 
EmployeeCount AS [Number of Employees],
    TerritoryDescription
FROM 
    TerritoryEmployeeCounts
WHERE 
    EmployeeCount = (SELECT MAX(EmployeeCount) FROM TerritoryEmployeeCounts);