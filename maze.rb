require 'pp'

Maze = "
**************************
*S* *                    *
* * *  *  *************  *
* *   *    ************  *
*    *                   *
************** ***********
*                        *
** ***********************
*      *              G  *
*  *      *********** *  *
*    *        ******* *  *
*       *                *
**************************
"

def split(m)
  m.split(/\n/).map{|line|
    line.split(//)
  }
end

def join(m, width=1)
  m.map{|line|
    line.map{|c| sprintf("%0#{width}s", c.to_s)}.join
  }
end

def pos(c)
  @maze.each_with_index{|line, y|
    if x = line.index(c)
      return [x,y]
    end
  }
  nil
end

def fill(rute)
  x,y = *(rute[-1])
  len = rute.size

  case @maze[y][x]
  when "*"
    return
  when "S"
  when "G"
    @rute ||= rute
    @rute = rute if len < @rute.size
    return
  when " "
    @maze[y][x] = len
  else
    return if len >= @maze[y][x]
    @maze[y][x] = len
  end

  fill(rute+[[x+1,y]])
  fill(rute+[[x-1,y]])
  fill(rute+[[x,y+1]])
  fill(rute+[[x,y-1]])
end

@maze = split(Maze)
@rute = nil

fill([pos("S")])

pp join(@maze, 3)
p @rute

m = split(Maze)
@rute[1..-2].each{|x,y|
  m[y][x] = "$"
}

pp join(m)
