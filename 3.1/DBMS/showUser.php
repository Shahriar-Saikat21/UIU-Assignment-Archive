<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>DBMS Assignment</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet"> 
    <link rel="stylesheet" href="style.css">
  </head>

  <body>
    
    <nav class="navbar bg-body-tertiary navbar">
        <div class="container">
          <h1 class="logo">DBMS ASSIGNMENT</h1>
        </div>
    </nav>

    <div class="container my-5">
        <button class="btn btn-primary"><a class="navbar-brand" href="index.html">Log Out</a></button>
        
        <form action="showUser.php" method="post" class="mt-3">
          <button type="submit" name="submit" class="btn btn-primary">Show All Users</button> 
        </form>       
    </div>

    <div class="container">
    <?php

      include('connection.php');

      if(isset($_POST['submit'])){ 

        $sql = "SELECT * FROM `member`";
        $result = mysqli_query($conn,$sql);

        $users = mysqli_fetch_all($result,MYSQLI_ASSOC);

        mysqli_free_result($result);
      }
      mysqli_close($conn);

    ?>
    <?php foreach($users as $i){ ?>
      <div class="card w-75 mb-3">
        <div class="card-body">
          <h5 class="card-title">User Name : <?php echo htmlspecialchars($i['name'])?></h5>
          <p class="card-text">Email Address: <?php echo htmlspecialchars($i['email'])?></p>
        </div>
      </div>
    <?php } ?>  
  </div>

  
</body>

</html>



