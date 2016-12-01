// Programmer: Dalton Lobosky
// Class: Comp Sci 153
// Homework 4
// Section A
//*****************************************************************************

#include "robot.h"
#include <iostream>


using namespace std;

class Industrial : public Robot
{  
  public:
    
    Industrial(string n, int nps);
    
  private:
 
  protected:
   
    int num_power_source; 
};

Industrial::Industrial(string n, int nps) : Robot(n)
{
  num_power_source = nps;
}



class Domestic : public Robot
{
  public:
    Domestic(string n, int ncpu, int napp);
  private:
  
  protected:
    int num_cpu;
    int num_apps;
    
};

Domestic::Domestic (string n, int ncpu, int napp) : Robot(n)
{
  num_cpu = ncpu;
  num_apps = napp;
}

class Bender : public Industrial
{
  public:
    Bender(string n, int nps, int gc);
    
  private:

    static const double speed1;
    static const double speed2;
    static const double strength1;
    static const double tough;
    static const double intel1;
    static const double intel2;

  protected:
    int num_geo_copro;
    
    float speed()
    {
      return (float) ((float)(speed1 * num_power_source) + (float)(speed2 * num_geo_copro));
    }
    
    float strength()
    {
      return (float) (strength1 * num_power_source);
    }
    
    float toughness()
    {
      return (float) (tough);
    }
    
    float intelligence()
    {
      return (float)(intel1 + (intel2 * num_geo_copro));
    }
};

const double Bender::speed1 = 0.3;
const double Bender::speed2 = 0.02;
const double Bender::strength1 = 0.55;
const double Bender::tough = 3.1415;
const double Bender::intel1 = 0.34;
const double Bender::intel2 = 1.3;

Bender::Bender(string n, int nps, int gc):Industrial(n,nps)
{
  num_geo_copro = gc;
}

class Welder : public Industrial
{
   public:
     Welder(string n, int nps, int nplat, float armdens);

   private:
   
     static const double speed3;
     static const double speed4;
     static const double strength1;
     static const double tough;
     static const double intel1;

   protected:
     int num_plates;
     float arm_density;

    float speed()
    {
      return (float)((speed3 * num_power_source) - (speed4 * num_plates * arm_density));
    }

    float strength()
    {
      return (float)(strength1 * num_power_source);
    }

    float toughness()
    {
      return (float)(tough * num_plates * arm_density);
    }

    float intelligence()
    {
      return (float)(intel1);
    }
};

const double Welder::speed3 = 0.1;
const double Welder::speed4 = 0.22;
const double Welder::strength1 = 3.15;
const double Welder::tough = 5.19;
const double Welder::intel1 = 0.45;

Welder::Welder(string n, int nps, int nplat, float armdens):Industrial(n,nps)
{
  num_plates = nplat;
  arm_density = armdens;
}

class Legged : public Domestic
{
   public:
      Legged(string n, int ncpu, int napp, int nlegs);

   private:

     static const double speed1;
     static const double speed2;
     static const double strength1;
     static const double tough;
     static const double intel1;

   protected:
    int num_legs;

    float speed()
    {
      return (float)(speed1 - (speed2 * num_legs * num_legs));
    }

    float strength()
    {
      return (float)(strength1);
    }

    float toughness()
    {
      return (float)(tough * (1 / num_legs));
    }

    float intelligence()
    {
      return (float)(intel1 * (num_cpu / num_apps));
    }
};

const double Legged::speed1 = 7.15;
const double Legged::speed2 = 0.04;
const double Legged::strength1 = 0.123;
const double Legged::tough = 1.4;
const double Legged::intel1 = 2.4;

Legged::Legged(string n, int ncpu, int napp, int nlegs):Domestic(n, ncpu, napp)
{
  num_legs = nlegs;;
}

class Wheeled : public Domestic
{
   public:
    Wheeled(string n, int ncpu, int napp, int nwheels);

   private:
     
     static const double speed1;
     static const double strength1;
     static const double tough1;
     static const double tough2;
     static const double intel1;
     
   protected:
    int num_wheels;

    float speed()
    {
      return (float)(speed1 * num_wheels * num_wheels);
    }

    float strength()
    {
      return (float)(strength1);
    }

    float toughness()
    {
      return (float)(tough1 - (tough2 * num_wheels));
    }

    float intelligence()
    {
      return (float)(intel1 * (num_cpu / num_apps));
    }
};

const double Wheeled::speed1 = 0.33;
const double Wheeled::strength1 = 4.444;
const double Wheeled::tough1 = 5.12;
const double Wheeled::tough2 = 0.7;
const double Wheeled::intel1 = 1.3;

Wheeled::Wheeled(string n, int ncpu, int napp, int nwheels):Domestic(n, ncpu, napp)
{
  num_wheels = nwheels;
}

class Hover : public Domestic
{
   public:

    Hover(string n, int ncpu, int napp, int nrckts, int nengn);

   private:

    static const double speed1;
    static const double strength1;
    static const double tough1;
    static const double intel2;
    static const double intel1;

   protected:
    int num_rockets;
    int num_engines;

    float speed()
    {
      return (float)(speed1 * num_rockets * num_engines);
    }

    float strength()
    {
      return (float)(strength1 * (1 / num_engines));
    }

    float toughness()
    {
      return (float)(tough1);
    }

    float intelligence()
    {
      return (float)(intel1 * (num_cpu / num_apps) - intel2 * (1 / num_rockets));
    }
};

const double Hover::speed1 = 0.59;
const double Hover::strength1 = 1.12;
const double Hover::tough1 = 0.99;
const double Hover::intel1 = 5.2;
const double Hover::intel2 = 0.8;

Hover::Hover(string n, int ncpu, int napp, int nrckts, int nengn):Domestic(n, ncpu, napp)
{
  num_rockets = nrckts;
  num_engines = nengn;
}





int main()
{ 
  int num_robots = 0;
  int robot_type, power, geo, plates, cpu, apps, legs, wheels, rockets, engines;
  int speed_avg, speed_sum, strength_sum, strength_avg, toughness_sum, toughness_avg;
  int intelligence_sum, intelligence_avg, index;
  string name;
  float armdensity;

  cin >> num_robots;

  Robot ** ra = new Robot*[num_robots];

  for (int i = 0; i < num_robots; i++)
  {
    cin >> robot_type;
    cin >> name;
    
    switch(robot_type)  
    {
      case BENDER:
      {         
        cin >> power;
        
        cin >> geo;
        
        ra[i] = new Bender(name, power, geo);
      }
      break;
      
      case WELDER:
      {
        cin >> power;
      
        cin >> plates;
        
        cin >> armdensity;
      
        ra[i] = new Welder(name, power, plates, armdensity);
      }
      break;
      
      case LEGGED:
      {
        cin >> cpu;
        
        cin >> apps;
  
        cin >> legs;
      
        ra[i] = new Legged(name, cpu, apps, legs);
      }
      break;

      case WHEELED:
      {
        cin >> cpu; 
        
        cin >> apps;
        
        cin >> wheels;
      
        ra[i] = new Wheeled(name, cpu, apps, wheels);
      }
      break;
    
      case HOVER:
      {
        cin >> cpu;
        
        cin >> apps;
        
        cin >> rockets;
        
        cin >> engines;
      
        ra[i] = new Hover(name, cpu, apps, rockets, engines);
      }
      break;
      
      default:
      break;
    }    
  }

//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
/*

SPEED

*/
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
  

  cout << "\n[SPEED]\n" << endl;
  
  speed_avg = 0;
  speed_sum = 0;
    
  for (int k = 0; k < num_robots; k++)
  {
    if (ra[k] -> speed() > 0)
    {
      speed_sum += (float) (ra[k] -> speed());   
    }
  }
  
  speed_avg = (float) (speed_sum / num_robots);
  
  cout << "The average speed is " << speed_avg << " circus-rings per second." << endl;  

  index = 0;

  for (int x = 1; x < num_robots; x++)
  {
    if ((ra[index] -> speed()) < (ra[x] -> speed()))
    {
      index = x;
    }  
   
  }    
 
  cout << "The highest speed value is " << ra[index] -> speed() << " by " << ra[index] -> getName() << "." << endl;
  
  index = 0;
  
  for (int j = 0; j < num_robots; j++) 
  {
    if ((ra[index] -> speed()) > (ra[j] -> speed()))
    {
      index = j;
    }
  }  
 
  cout << "The lowest speed value is " << ra[index] -> speed() << " by " << ra[index] -> getName() << "." << endl;
  

//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
/*

STRENGTH

*/
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
  

  cout << "\n[STRENGTH]\n" << endl;
  
  for (int k = 0; k < num_robots; k++)
  {
      strength_sum += ra[k] -> strength();   
  }
  
  strength_avg = (float) (strength_sum / num_robots);
  
  cout << "The average strength is " << strength_avg << " dinosaur-power." << endl;  
  
  index = 0;
  
  for (int x = 1; x < num_robots; x++)
  {
    if ((ra[index] -> strength()) < (ra[x] -> strength()))
    {
      index = x;
    }
  }
    
  cout << "The highest strength value is " << ra[index] -> strength() << " by " << ra[index] -> getName() << "." << endl;

  index = 0;

  for (int j = 1; j < num_robots; j++)
  {
    if ((ra[index] -> strength()) > (ra[j] -> strength()))
    {   
      index = j;
    }
  }
    
  cout << "The lowest strength value is " << ra[index] -> strength() << " by " << ra[index] -> getName() << "." << endl;
   
   
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
/*

TOUGHNESS

*/
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII


  cout << "\n[TOUGHNESS]\n" << endl;

  for (int k = 0; k < num_robots; k++)
  {
    if (ra[k] -> toughness() > 0)
    {
      toughness_sum += ra[k] -> toughness();
    }
  }

  toughness_avg = (float) (toughness_sum / num_robots);

  cout << "The average toughness is " << toughness_avg << " wrecking-balls." << endl;
  
  index = 0;

  for (int x = 1; x < num_robots; x++)
  {
    if (ra[index] -> toughness() < ra[x] -> toughness())
    {
      index = x;
    }
  }
  
  cout << "The highest toughness value is " << ra[index] -> toughness() << " by " << ra[index] -> getName() << "." << endl;

  index = 0;

  for (int j = 1; j < num_robots; j++)
  {
    if (ra[index] -> toughness() > ra[j] -> toughness())
    {
      index = j;
    }
  }
  
  cout << "The lowest toughness value is " << ra[index] -> toughness() << " by " << ra[index] -> getName() << "." << endl;


//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
/*

INTELLIGENCE

*/
//IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII


  cout << "\n[INTELLIGENCE]\n" << endl;

  for (int k = 0; k < num_robots; k++)
  {
    if (ra[k] -> intelligence() > 0)
    {
      intelligence_sum += ra[k] -> intelligence();
    }
  }

  intelligence_avg = (float) (intelligence_sum / num_robots);

  cout << "The average intelligence is " << intelligence_avg << " nano-Turings." << endl;

  index = 0;

  for (int x = 1; x < num_robots; x++)
  {
    if (ra[index] -> intelligence() < ra[x] -> intelligence())
    {
      index = x;
    }
  }  
 
  cout << "The highest intelligence value is " << ra[index] -> intelligence() << " by " << ra[index] -> getName() << "." << endl;
 
  index = 0;

  for (int j = 1; j < num_robots; j++)
  {
    if (ra[index] -> intelligence() > ra[j] -> intelligence())
    {
      index = j;
    }
  }

  cout << "The lowest intelligence value is " << ra[index] -> intelligence() << " by " << ra[index] -> getName() << ".\n\n\n\n" << endl;


    
  for (int h = 0; h < num_robots ; h++)
  {
    delete[] ra[h];
  }
  
  delete[] ra;
  
  ra = NULL;
 
  return 0;

}


